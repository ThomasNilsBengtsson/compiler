// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 16 "parser.yy"

  #define YY_DECL yy::parser::symbol_type yylex()
  YY_DECL;
  
  Node* root;
  extern int yylineno;

#line 54 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 127 "parser.tab.cc"

  /// Build a parser object.
  parser::parser ()
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr)
#else

#endif
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_ClassDeclarationList: // ClassDeclarationList
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainClassParams: // MainClassParams
      case symbol_kind::S_StatementListM: // StatementListM
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarationCL: // VarDeclarationCL
      case symbol_kind::S_MethodDeclarationCL: // MethodDeclarationCL
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclarationParamsOpt: // MethodDeclarationParamsOpt
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_ExpressionParamsOpt: // ExpressionParamsOpt
      case symbol_kind::S_ExpressionParams: // ExpressionParams
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.YY_MOVE_OR_COPY< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_SYSTEM_OUT_PRINTLN: // SYSTEM_OUT_PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_ClassDeclarationList: // ClassDeclarationList
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainClassParams: // MainClassParams
      case symbol_kind::S_StatementListM: // StatementListM
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarationCL: // VarDeclarationCL
      case symbol_kind::S_MethodDeclarationCL: // MethodDeclarationCL
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclarationParamsOpt: // MethodDeclarationParamsOpt
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_ExpressionParamsOpt: // ExpressionParamsOpt
      case symbol_kind::S_ExpressionParams: // ExpressionParams
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_SYSTEM_OUT_PRINTLN: // SYSTEM_OUT_PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_ClassDeclarationList: // ClassDeclarationList
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainClassParams: // MainClassParams
      case symbol_kind::S_StatementListM: // StatementListM
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarationCL: // VarDeclarationCL
      case symbol_kind::S_MethodDeclarationCL: // MethodDeclarationCL
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclarationParamsOpt: // MethodDeclarationParamsOpt
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_ExpressionParamsOpt: // ExpressionParamsOpt
      case symbol_kind::S_ExpressionParams: // ExpressionParams
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.copy< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_SYSTEM_OUT_PRINTLN: // SYSTEM_OUT_PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_ClassDeclarationList: // ClassDeclarationList
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainClassParams: // MainClassParams
      case symbol_kind::S_StatementListM: // StatementListM
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarationCL: // VarDeclarationCL
      case symbol_kind::S_MethodDeclarationCL: // MethodDeclarationCL
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclarationParamsOpt: // MethodDeclarationParamsOpt
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_ExpressionParamsOpt: // ExpressionParamsOpt
      case symbol_kind::S_ExpressionParams: // ExpressionParams
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        value.move< Node * > (that.value);
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_SYSTEM_OUT_PRINTLN: // SYSTEM_OUT_PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex ());
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_root: // root
      case symbol_kind::S_Goal: // Goal
      case symbol_kind::S_ClassDeclarationList: // ClassDeclarationList
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_MainClassParams: // MainClassParams
      case symbol_kind::S_StatementListM: // StatementListM
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_VarDeclarationCL: // VarDeclarationCL
      case symbol_kind::S_MethodDeclarationCL: // MethodDeclarationCL
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_MethodDeclarationParamsOpt: // MethodDeclarationParamsOpt
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_Parameter: // Parameter
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_ExpressionParamsOpt: // ExpressionParamsOpt
      case symbol_kind::S_ExpressionParams: // ExpressionParams
      case symbol_kind::S_factor: // factor
      case symbol_kind::S_Identifier: // Identifier
        yylhs.value.emplace< Node * > ();
        break;

      case symbol_kind::S_PLUSOP: // PLUSOP
      case symbol_kind::S_MINUSOP: // MINUSOP
      case symbol_kind::S_MULTOP: // MULTOP
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_LP: // LP
      case symbol_kind::S_RP: // RP
      case symbol_kind::S_LBRACE: // LBRACE
      case symbol_kind::S_RBRACE: // RBRACE
      case symbol_kind::S_ASSIGN: // ASSIGN
      case symbol_kind::S_AND: // AND
      case symbol_kind::S_OR: // OR
      case symbol_kind::S_LT: // LT
      case symbol_kind::S_GT: // GT
      case symbol_kind::S_EQ: // EQ
      case symbol_kind::S_NOT: // NOT
      case symbol_kind::S_STATIC: // STATIC
      case symbol_kind::S_PUBLIC: // PUBLIC
      case symbol_kind::S_CLASS: // CLASS
      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_BOOLEAN: // BOOLEAN
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_SYSTEM_OUT_PRINTLN: // SYSTEM_OUT_PRINTLN
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_TRUE: // TRUE
      case symbol_kind::S_FALSE: // FALSE
      case symbol_kind::S_THIS: // THIS
      case symbol_kind::S_NEW: // NEW
      case symbol_kind::S_LENGTH: // LENGTH
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_SEMICOLON: // SEMICOLON
      case symbol_kind::S_COMMA: // COMMA
      case symbol_kind::S_DOT: // DOT
      case symbol_kind::S_LBRACKET: // LBRACKET
      case symbol_kind::S_RBRACKET: // RBRACKET
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // root: Goal
#line 54 "parser.yy"
                {root = yystack_[0].value.as < Node * > ();}
#line 843 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass "END of FILE"
#line 59 "parser.yy"
               {

     yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);   
     yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());    
  }
#line 853 "parser.tab.cc"
    break;

  case 4: // Goal: MainClass ClassDeclarationList "END of FILE"
#line 64 "parser.yy"
                                      {
    yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 863 "parser.tab.cc"
    break;

  case 5: // ClassDeclarationList: ClassDeclaration
#line 71 "parser.yy"
                     {
      yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
      yylhs.value.as < Node * > () -> children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 872 "parser.tab.cc"
    break;

  case 6: // ClassDeclarationList: ClassDeclarationList ClassDeclaration
#line 75 "parser.yy"
                                           {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 881 "parser.tab.cc"
    break;

  case 7: // MainClass: PUBLIC CLASS Identifier LBRACE MainClassParams RBRACE
#line 81 "parser.yy"
                                                                 { 
                yylhs.value.as < Node * > () = new Node("MainClass", yystack_[3].value.as < Node * > ()->value, yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());

          }
#line 892 "parser.tab.cc"
    break;

  case 8: // MainClassParams: PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement StatementListM RBRACE
#line 89 "parser.yy"
                                                                                                                          { 
                yylhs.value.as < Node * > () = new Node("MainClass", yystack_[5].value.as < Node * > ()->value, yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());

          }
#line 904 "parser.tab.cc"
    break;

  case 9: // StatementListM: %empty
#line 99 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno); }
#line 910 "parser.tab.cc"
    break;

  case 10: // StatementListM: Statement
#line 100 "parser.yy"
              {
        yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 919 "parser.tab.cc"
    break;

  case 11: // StatementListM: StatementListM Statement
#line 104 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 928 "parser.tab.cc"
    break;

  case 12: // ClassDeclaration: CLASS Identifier LBRACE VarDeclarationCL MethodDeclarationCL RBRACE
#line 111 "parser.yy"
                                                                                      { 
            yylhs.value.as < Node * > () = new Node("ClassDeclaration", yystack_[4].value.as < Node * > ()->value, yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 939 "parser.tab.cc"
    break;

  case 13: // VarDeclarationCL: %empty
#line 120 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno); }
#line 945 "parser.tab.cc"
    break;

  case 14: // VarDeclarationCL: VarDeclaration
#line 121 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 954 "parser.tab.cc"
    break;

  case 15: // VarDeclarationCL: VarDeclarationCL VarDeclaration
#line 125 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 963 "parser.tab.cc"
    break;

  case 16: // MethodDeclarationCL: %empty
#line 131 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno); }
#line 969 "parser.tab.cc"
    break;

  case 17: // MethodDeclarationCL: MethodDeclaration
#line 132 "parser.yy"
                      {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 978 "parser.tab.cc"
    break;

  case 18: // MethodDeclarationCL: MethodDeclarationCL MethodDeclaration
#line 136 "parser.yy"
                                           {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 987 "parser.tab.cc"
    break;

  case 19: // MethodDeclaration: PUBLIC Type Identifier LP MethodDeclarationParamsOpt RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE
#line 142 "parser.yy"
                                                                                                                                           { 
                yylhs.value.as < Node * > () = new Node("MethodDeclaration", yystack_[9].value.as < Node * > ()->value, yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
               
          }
#line 1001 "parser.tab.cc"
    break;

  case 20: // MethodDeclarationParamsOpt: %empty
#line 153 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationParamsOpt", "", yylineno); }
#line 1007 "parser.tab.cc"
    break;

  case 21: // MethodDeclarationParamsOpt: MethodDeclarationParams
#line 154 "parser.yy"
                            {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationParamsOpt", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1016 "parser.tab.cc"
    break;

  case 22: // MethodDeclarationParams: Parameter
#line 160 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1022 "parser.tab.cc"
    break;

  case 23: // MethodDeclarationParams: MethodDeclarationParams COMMA Parameter
#line 161 "parser.yy"
                                            { 
          yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); 
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
      }
#line 1031 "parser.tab.cc"
    break;

  case 24: // Parameter: Type Identifier
#line 169 "parser.yy"
                    {
         yylhs.value.as < Node * > () = new Node("Parameter", "", yylineno);
         yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
         yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1041 "parser.tab.cc"
    break;

  case 25: // MethodDeclarationBody: %empty
#line 178 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno); }
#line 1047 "parser.tab.cc"
    break;

  case 26: // MethodDeclarationBody: VarDeclaration
#line 179 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1056 "parser.tab.cc"
    break;

  case 27: // MethodDeclarationBody: Statement
#line 183 "parser.yy"
               {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1065 "parser.tab.cc"
    break;

  case 28: // MethodDeclarationBody: MethodDeclarationBody VarDeclaration
#line 187 "parser.yy"
                                          {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1074 "parser.tab.cc"
    break;

  case 29: // MethodDeclarationBody: MethodDeclarationBody Statement
#line 191 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1083 "parser.tab.cc"
    break;

  case 30: // VarDeclaration: Type Identifier SEMICOLON
#line 196 "parser.yy"
                                          { 
                yylhs.value.as < Node * > () = new Node("VarDeclaration", yystack_[1].value.as < Node * > ()->value, yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1093 "parser.tab.cc"
    break;

  case 31: // Type: INT LBRACKET RBRACKET
#line 204 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("IntArray", "", yylineno); }
#line 1099 "parser.tab.cc"
    break;

  case 32: // Type: BOOLEAN
#line 205 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno); }
#line 1105 "parser.tab.cc"
    break;

  case 33: // Type: INT
#line 206 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Int", "", yylineno); }
#line 1111 "parser.tab.cc"
    break;

  case 34: // Type: Identifier
#line 207 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Identifier", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1117 "parser.tab.cc"
    break;

  case 35: // StatementMulti: %empty
#line 212 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno); }
#line 1123 "parser.tab.cc"
    break;

  case 36: // StatementMulti: Statement
#line 213 "parser.yy"
              {
        yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1132 "parser.tab.cc"
    break;

  case 37: // StatementMulti: StatementMulti Statement
#line 217 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1141 "parser.tab.cc"
    break;

  case 38: // Statement: LBRACE StatementMulti RBRACE
#line 224 "parser.yy"
                                        {
            yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        }
#line 1150 "parser.tab.cc"
    break;

  case 39: // Statement: IF LP expression RP Statement ELSE Statement
#line 228 "parser.yy"
                                                       { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1161 "parser.tab.cc"
    break;

  case 40: // Statement: IF LP expression RP Statement
#line 234 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1171 "parser.tab.cc"
    break;

  case 41: // Statement: WHILE LP expression RP Statement
#line 239 "parser.yy"
                                           { 
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1181 "parser.tab.cc"
    break;

  case 42: // Statement: SYSTEM_OUT_PRINTLN LP expression RP SEMICOLON
#line 244 "parser.yy"
                                                        { 
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1190 "parser.tab.cc"
    break;

  case 43: // Statement: Identifier ASSIGN expression SEMICOLON
#line 248 "parser.yy"
                                                 { 
                yylhs.value.as < Node * > () = new Node("AssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1200 "parser.tab.cc"
    break;

  case 44: // Statement: Identifier LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 253 "parser.yy"
                                                                              { 
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1211 "parser.tab.cc"
    break;

  case 45: // expression: expression PLUSOP expression
#line 260 "parser.yy"
                                         { 
                yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1221 "parser.tab.cc"
    break;

  case 46: // expression: expression MINUSOP expression
#line 265 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1231 "parser.tab.cc"
    break;

  case 47: // expression: expression MULTOP expression
#line 270 "parser.yy"
                                       { 
                yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1241 "parser.tab.cc"
    break;

  case 48: // expression: expression AND expression
#line 275 "parser.yy"
                                    { 
                yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1251 "parser.tab.cc"
    break;

  case 49: // expression: expression OR expression
#line 280 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1261 "parser.tab.cc"
    break;

  case 50: // expression: expression LT expression
#line 285 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("LtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1271 "parser.tab.cc"
    break;

  case 51: // expression: expression GT expression
#line 290 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("GtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1281 "parser.tab.cc"
    break;

  case 52: // expression: expression EQ expression
#line 295 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("EqExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1291 "parser.tab.cc"
    break;

  case 53: // expression: expression LBRACKET expression RBRACKET
#line 301 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1301 "parser.tab.cc"
    break;

  case 54: // expression: expression DOT LENGTH
#line 307 "parser.yy"
                                {
                yylhs.value.as < Node * > () = new Node("ArrayLength", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1310 "parser.tab.cc"
    break;

  case 55: // expression: expression DOT Identifier LP ExpressionParamsOpt RP
#line 311 "parser.yy"
                                                              {
                yylhs.value.as < Node * > () = new Node("MethodCall","", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              
            }
#line 1322 "parser.tab.cc"
    break;

  case 56: // expression: TRUE
#line 319 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "true", yylineno); }
#line 1328 "parser.tab.cc"
    break;

  case 57: // expression: FALSE
#line 320 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "false", yylineno); }
#line 1334 "parser.tab.cc"
    break;

  case 58: // expression: Identifier
#line 321 "parser.yy"
                     { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1340 "parser.tab.cc"
    break;

  case 59: // expression: THIS
#line 322 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 1346 "parser.tab.cc"
    break;

  case 60: // expression: NEW INT LBRACKET expression RBRACKET
#line 323 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("NewArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 1352 "parser.tab.cc"
    break;

  case 61: // expression: NEW Identifier LP RP
#line 324 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("NewObjectExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); }
#line 1358 "parser.tab.cc"
    break;

  case 62: // expression: NOT expression
#line 325 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1364 "parser.tab.cc"
    break;

  case 63: // expression: LP expression RP
#line 326 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("Expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1370 "parser.tab.cc"
    break;

  case 64: // expression: factor
#line 327 "parser.yy"
                  { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1376 "parser.tab.cc"
    break;

  case 65: // ExpressionParamsOpt: %empty
#line 333 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("ExpressionParamsOpt", "", yylineno); }
#line 1382 "parser.tab.cc"
    break;

  case 66: // ExpressionParamsOpt: ExpressionParams
#line 334 "parser.yy"
                              {
            yylhs.value.as < Node * > () = new Node("ExpressionParamsOpt", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1391 "parser.tab.cc"
    break;

  case 67: // ExpressionParams: expression
#line 340 "parser.yy"
                      {
            yylhs.value.as < Node * > () = new Node("ExpressionParams", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1400 "parser.tab.cc"
    break;

  case 68: // ExpressionParams: ExpressionParams COMMA expression
#line 344 "parser.yy"
                                               {
            yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
            }
#line 1409 "parser.tab.cc"
    break;

  case 69: // factor: INT
#line 350 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno); /* printf("r1 "); */}
#line 1415 "parser.tab.cc"
    break;

  case 70: // Identifier: IDENTIFIER
#line 353 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); /* printf("r7 "); */}
#line 1421 "parser.tab.cc"
    break;


#line 1425 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -57;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -10,    33,    20,   -57,    30,    19,   -57,   -57,    19,    37,
     -57,   -57,    49,    50,   -57,   -57,    51,    91,    53,    76,
      52,   -57,    86,   -57,    19,   -57,    68,   -57,    55,    91,
      32,   -57,   -57,    60,    85,   -57,    19,   -57,   -57,   -57,
     101,   116,   106,    91,   107,   122,    87,   -57,    19,    99,
     131,    91,   -57,    19,    -2,   -57,   139,   100,   145,   150,
     158,   319,   -57,   -57,    -3,   157,   128,   -57,    -3,   218,
     218,   218,   218,   -57,   -57,   218,   218,   100,   -57,   -57,
     -57,   218,   218,   -57,   -57,   -57,     0,   167,   -57,   -57,
     184,   199,   205,   242,    61,   100,   256,   -25,   134,   169,
     218,   218,   218,   100,   218,   218,   218,   218,   218,   -19,
     218,   100,   138,   168,   -57,   166,   330,   -57,   -57,   218,
     182,     6,     6,   -25,   165,    64,   298,    24,    24,   312,
     -57,   186,   129,   -57,   -57,   -57,   218,   -57,   -57,   146,
     -57,   100,   218,   -57,   270,   -57,   -57,   284,   187,   164,
     -57,   -57,   218,   284
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     3,     0,     0,
       5,    70,     0,     0,     4,     6,     0,    13,     0,     0,
      33,    32,    16,    14,     0,    34,     0,     7,     0,     0,
       0,    17,    15,     0,     0,    31,     0,    12,    18,    30,
       0,     0,     0,    20,     0,     0,    21,    22,     0,     0,
       0,     0,    24,     0,    25,    23,     0,    35,     0,     0,
       0,     0,    26,    27,    34,     0,     0,    36,     0,     0,
       0,     0,     0,    28,    29,     0,     0,     0,    38,    37,
      69,     0,     0,    56,    57,    59,     0,     0,    64,    58,
       0,     0,     0,     0,     0,     9,     0,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,    10,    63,     0,
       0,    45,    46,    47,    40,    48,    49,    50,    51,    52,
      54,     0,     0,    41,    42,    19,     0,     8,    11,     0,
      61,     0,    65,    53,     0,    60,    39,    67,     0,    66,
      44,    55,     0,    68
  };

  const short
  parser::yypgoto_[] =
  {
     -57,   -57,   -57,   -57,   -57,   -57,   -57,   185,   -57,   -57,
     196,   -57,   -57,   176,   -57,   -20,   -11,   -57,   -56,    12,
     -57,   -57,   -57,    -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     9,     4,    19,   116,    10,    22,    30,
      31,    45,    46,    47,    61,    23,    24,    66,    63,    87,
     148,   149,    88,    89
  };

  const unsigned char
  parser::yytable_[] =
  {
      12,    67,    32,    13,    20,    74,    98,    57,    75,     1,
      79,   102,    25,   109,   110,   130,    11,    25,    36,    33,
       6,    95,    21,    58,    25,    59,    60,   100,   101,   102,
       7,    41,    48,    11,    62,    11,    76,    14,    25,   117,
      48,    73,    37,    52,   109,   110,    25,   124,    56,    64,
       8,    29,    68,     5,    11,   133,    64,     8,    16,    17,
     138,    68,   109,   110,   100,   101,   102,   100,   101,   102,
      18,    26,    68,   104,   105,   106,   107,   108,   106,   107,
     108,    99,    90,    91,    92,   146,    27,    93,    94,    34,
      68,    28,    20,    96,    97,    35,    39,    20,    68,   109,
     110,   115,   109,   110,   131,    29,    68,    40,    42,    57,
      21,    68,   121,   122,   123,    21,   125,   126,   127,   128,
     129,    11,   132,    43,    51,    58,    11,    59,    60,    44,
      50,   139,   100,   101,   102,    11,    68,    57,    78,    53,
      54,   104,   105,   106,   107,   108,    49,    65,   144,   100,
     101,   102,    69,    58,   147,    59,    60,    70,   104,   105,
     106,   107,   108,    11,   153,    71,    77,   109,   110,   143,
     100,   101,   102,   119,   134,   103,   120,   136,   135,   104,
     105,   106,   107,   108,   109,   110,   145,   100,   101,   102,
     140,   141,   111,   142,    15,   151,   104,   105,   106,   107,
     108,   152,   100,   101,   102,   109,   110,   112,   100,   101,
     102,   104,   105,   106,   107,   108,     0,   104,   105,   106,
     107,   108,   109,   110,    80,    81,    38,    55,     0,     0,
       0,     0,     0,     0,     0,    82,     0,   109,   110,     0,
       0,   113,     0,   109,   110,   100,   101,   102,    83,    84,
      85,    86,     0,    11,   104,   105,   106,   107,   108,   100,
     101,   102,     0,     0,   118,     0,     0,     0,   104,   105,
     106,   107,   108,   100,   101,   102,     0,     0,   114,     0,
     109,   110,   104,   105,   106,   107,   108,   100,   101,   102,
       0,     0,     0,     0,   109,   110,   104,   105,   106,   107,
     108,   100,   101,   102,     0,     0,   150,     0,   109,   110,
     104,     0,   106,   107,   108,   100,   101,   102,     0,     0,
       0,     0,   109,   110,     0,    20,   106,   107,    57,     0,
       0,     0,     0,     0,     0,     0,   109,   110,     0,    57,
     137,     0,     0,    21,    58,     0,    59,    60,    72,     0,
     109,   110,     0,     0,    11,    58,     0,    59,    60,     0,
       0,     0,     0,     0,     0,    11
  };

  const short
  parser::yycheck_[] =
  {
       5,    57,    22,     8,     6,    61,     6,     9,    11,    19,
      66,     5,    17,    38,    39,    34,    35,    22,    29,    24,
       0,    77,    24,    25,    29,    27,    28,     3,     4,     5,
       0,    36,    43,    35,    54,    35,    39,     0,    43,    95,
      51,    61,    10,    48,    38,    39,    51,   103,    53,    54,
      20,    19,    57,    20,    35,   111,    61,    20,     9,     9,
     116,    66,    38,    39,     3,     4,     5,     3,     4,     5,
      19,    18,    77,    12,    13,    14,    15,    16,    14,    15,
      16,    86,    70,    71,    72,   141,    10,    75,    76,    21,
      95,    39,     6,    81,    82,    40,    36,     6,   103,    38,
      39,    40,    38,    39,   109,    19,   111,    22,     7,     9,
      24,   116,   100,   101,   102,    24,   104,   105,   106,   107,
     108,    35,   110,     7,    37,    25,    35,    27,    28,    23,
       8,   119,     3,     4,     5,    35,   141,     9,    10,    40,
       9,    12,    13,    14,    15,    16,    39,     8,   136,     3,
       4,     5,     7,    25,   142,    27,    28,     7,    12,    13,
      14,    15,    16,    35,   152,     7,     9,    38,    39,    40,
       3,     4,     5,    39,    36,     8,     7,    11,    10,    12,
      13,    14,    15,    16,    38,    39,    40,     3,     4,     5,
       8,    26,     8,     7,     9,     8,    12,    13,    14,    15,
      16,    37,     3,     4,     5,    38,    39,     8,     3,     4,
       5,    12,    13,    14,    15,    16,    -1,    12,    13,    14,
      15,    16,    38,    39,     6,     7,    30,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    -1,    38,    39,    -1,
      -1,    36,    -1,    38,    39,     3,     4,     5,    30,    31,
      32,    33,    -1,    35,    12,    13,    14,    15,    16,     3,
       4,     5,    -1,    -1,     8,    -1,    -1,    -1,    12,    13,
      14,    15,    16,     3,     4,     5,    -1,    -1,    36,    -1,
      38,    39,    12,    13,    14,    15,    16,     3,     4,     5,
      -1,    -1,    -1,    -1,    38,    39,    12,    13,    14,    15,
      16,     3,     4,     5,    -1,    -1,    36,    -1,    38,    39,
      12,    -1,    14,    15,    16,     3,     4,     5,    -1,    -1,
      -1,    -1,    38,    39,    -1,     6,    14,    15,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    39,    -1,     9,
      10,    -1,    -1,    24,    25,    -1,    27,    28,    29,    -1,
      38,    39,    -1,    -1,    35,    25,    -1,    27,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,    19,    42,    43,    45,    20,     0,     0,    20,    44,
      48,    35,    64,    64,     0,    48,     9,     9,    19,    46,
       6,    24,    49,    56,    57,    64,    18,    10,    39,    19,
      50,    51,    56,    64,    21,    40,    57,    10,    51,    36,
      22,    64,     7,     7,    23,    52,    53,    54,    57,    39,
       8,    37,    64,    40,     9,    54,    64,     9,    25,    27,
      28,    55,    56,    59,    64,     8,    58,    59,    64,     7,
       7,     7,    29,    56,    59,    11,    39,     9,    10,    59,
       6,     7,    17,    30,    31,    32,    33,    60,    63,    64,
      60,    60,    60,    60,    60,    59,    60,    60,     6,    64,
       3,     4,     5,     8,    12,    13,    14,    15,    16,    38,
      39,     8,     8,    36,    36,    40,    47,    59,     8,    39,
       7,    60,    60,    60,    59,    60,    60,    60,    60,    60,
      34,    64,    60,    59,    36,    10,    11,    10,    59,    60,
       8,    26,     7,    40,    60,    40,    59,    60,    61,    62,
      36,     8,    37,    60
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    46,    47,
      47,    47,    48,    49,    49,    49,    50,    50,    50,    51,
      52,    52,    53,    53,    54,    55,    55,    55,    55,    55,
      56,    57,    57,    57,    57,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    62,    62,    63,
      64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     1,     2,     6,    14,     0,
       1,     2,     6,     0,     1,     2,     0,     1,     2,    12,
       0,     1,     1,     3,     2,     0,     1,     1,     2,     2,
       3,     3,     1,     1,     1,     0,     1,     2,     3,     7,
       5,     5,     5,     4,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     3,     6,     1,     1,     1,     1,
       5,     4,     2,     3,     1,     0,     1,     1,     3,     1,
       1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"END of FILE\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "INT", "LP", "RP", "LBRACE", "RBRACE", "ASSIGN", "AND", "OR",
  "LT", "GT", "EQ", "NOT", "STATIC", "PUBLIC", "CLASS", "VOID", "MAIN",
  "STRING", "BOOLEAN", "IF", "ELSE", "WHILE", "SYSTEM_OUT_PRINTLN",
  "RETURN", "TRUE", "FALSE", "THIS", "NEW", "LENGTH", "IDENTIFIER",
  "SEMICOLON", "COMMA", "DOT", "LBRACKET", "RBRACKET", "$accept", "root",
  "Goal", "ClassDeclarationList", "MainClass", "MainClassParams",
  "StatementListM", "ClassDeclaration", "VarDeclarationCL",
  "MethodDeclarationCL", "MethodDeclaration", "MethodDeclarationParamsOpt",
  "MethodDeclarationParams", "Parameter", "MethodDeclarationBody",
  "VarDeclaration", "Type", "StatementMulti", "Statement", "expression",
  "ExpressionParamsOpt", "ExpressionParams", "factor", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    54,    54,    59,    64,    71,    75,    81,    89,    99,
     100,   104,   111,   120,   121,   125,   131,   132,   136,   142,
     153,   154,   160,   161,   169,   178,   179,   183,   187,   191,
     196,   204,   205,   206,   207,   212,   213,   217,   224,   228,
     234,   239,   244,   248,   253,   260,   265,   270,   275,   280,
     285,   290,   295,   301,   307,   311,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   333,   334,   340,   344,   350,
     353
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 2032 "parser.tab.cc"

#line 357 "parser.yy"
