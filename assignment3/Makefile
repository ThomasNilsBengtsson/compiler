compiler: lex.yy.c parser.tab.o main.cc symbol_table.cc semantic_analyzer.cc ir.cc ir_generator.cc bytecode.cc interpreter.cc
		g++ -g -w -ocompiler parser.tab.o lex.yy.c main.cc symbol_table.cc semantic_analyzer.cc ir.cc ir_generator.cc bytecode.cc interpreter.cc -std=c++14
parser.tab.o: parser.tab.cc
		g++ -g -w -c parser.tab.cc -std=c++14
parser.tab.cc: parser.yy
		bison parser.yy
lex.yy.c: lexer.flex parser.tab.cc
		flex lexer.flex
tree:
		dot -Tpdf tree.dot -otree.pdf
cfg:
		dot -Tpdf cfg.dot -ocfg.pdf
clean:
		rm -f parser.tab.* lex.yy.c* compiler stack.hh position.hh location.hh tree.dot tree.pdf program.bc cfg.dot cfg.pdf
		rm -R compiler.dSYM