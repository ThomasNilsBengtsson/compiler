Object parseExpression(String expr) {
    expr = expr.trim();

    if (expr.matches("\\d+")) {
        return "INTEGER_LITERAL: " + expr;
    }

    if (expr.equals("true") || expr.equals("false")) {
        return "BOOLEAN_LITERAL: " + expr;
    }

    if (expr.matches("[a-zA-Z_][a-zA-Z0-9_]*")) {
        return "Identifier: " + expr;
    }

    if (expr.equals("this")) {
        return "Keyword: this";
    }

    if (expr.matches("new int\\[.*\\]")) {
        return "Array Allocation: " + expr;
    }

    if (expr.matches("new [a-zA-Z_][a-zA-Z0-9_]*\\(\\)")) {
        return "Object Instantiation: " + expr;
    }

    if (expr.startsWith("!")) {
        return "Negation: " + parseExpression(expr.substring(1));
    }

    if (expr.startsWith("(") && expr.endsWith(")")) {
        return "Parenthesized: " + parseExpression(expr.substring(1, expr.length() - 1));
    }

    if (expr.contains("&&") || expr.contains("||")) {
        String[] parts = expr.split("&&|\\|\\|");
        return "Logical Expression: " + parseExpression(parts[0]) + " with " + parseExpression(parts[1]);
    }

    if (expr.contains("<") || expr.contains(">") || expr.contains("==")) {
        String[] parts = expr.split("<|>|==");
        return "Comparison Expression: " + parseExpression(parts[0]) + " compared with " + parseExpression(parts[1]);
    }

    if (expr.contains("+") || expr.contains("-") || expr.contains("*")) {
        String[] parts = expr.split("\\+|-|\\*");
        return "Arithmetic Expression: " + parseExpression(parts[0]) + " with " + parseExpression(parts[1]);
    }

    if (expr.endsWith(".length")) {
        return "Array Length Access: " + expr.replace(".length", "");
    }

    if (expr.matches(".*\\.[a-zA-Z_][a-zA-Z0-9_]*\\(.*\\)")) {
        return "Method Call: " + expr;
    }

    if (expr.contains("[") && expr.endsWith("]")) {
        String arrayName = expr.substring(0, expr.indexOf("["));
        String index = expr.substring(expr.indexOf("[") + 1, expr.length() - 1);
        return "Array Access: " + arrayName + " at index " + parseExpression(index);
    }

    return "Unknown Expression: " + expr;
}

void main(String[] args) {
    testExpression("5 + 3");
    testExpression("x && y");
    testExpression("a < b");
    testExpression("arr[2]");
    testExpression("obj.length");
    testExpression("obj.method(3, y)");
    testExpression("true");
    testExpression("false");
    testExpression("this");
    testExpression("new int[5]");
    testExpression("new MyClass()");
    testExpression("!flag");
    testExpression("(a + b) * c");
}
