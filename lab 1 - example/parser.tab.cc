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
#line 838 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass "END of FILE"
#line 59 "parser.yy"
               {

     yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);   
     yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());    
  }
#line 848 "parser.tab.cc"
    break;

  case 4: // Goal: MainClass ClassDeclarationList "END of FILE"
#line 64 "parser.yy"
                                      {
    yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
    yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 858 "parser.tab.cc"
    break;

  case 5: // ClassDeclarationList: ClassDeclaration
#line 71 "parser.yy"
                     {
      yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
      yylhs.value.as < Node * > () -> children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 867 "parser.tab.cc"
    break;

  case 6: // ClassDeclarationList: ClassDeclarationList ClassDeclaration
#line 75 "parser.yy"
                                           {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 876 "parser.tab.cc"
    break;

  case 7: // MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement StatementListM RBRACE RBRACE
#line 81 "parser.yy"
                                                                                                                                                          { 
                yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);

               yylhs.value.as < Node * > ()->children.push_back(yystack_[16].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());

          }
#line 890 "parser.tab.cc"
    break;

  case 8: // StatementListM: %empty
#line 93 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno); }
#line 896 "parser.tab.cc"
    break;

  case 9: // StatementListM: Statement
#line 94 "parser.yy"
              {
        yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 905 "parser.tab.cc"
    break;

  case 10: // StatementListM: StatementListM Statement
#line 98 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 914 "parser.tab.cc"
    break;

  case 11: // ClassDeclaration: CLASS Identifier LBRACE VarDeclarationCL MethodDeclarationCL RBRACE
#line 105 "parser.yy"
                                                                                      { 
            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 925 "parser.tab.cc"
    break;

  case 12: // VarDeclarationCL: %empty
#line 114 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno); }
#line 931 "parser.tab.cc"
    break;

  case 13: // VarDeclarationCL: VarDeclaration
#line 115 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 940 "parser.tab.cc"
    break;

  case 14: // VarDeclarationCL: VarDeclarationCL VarDeclaration
#line 119 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 949 "parser.tab.cc"
    break;

  case 15: // MethodDeclarationCL: %empty
#line 125 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno); }
#line 955 "parser.tab.cc"
    break;

  case 16: // MethodDeclarationCL: MethodDeclaration
#line 126 "parser.yy"
                      {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 964 "parser.tab.cc"
    break;

  case 17: // MethodDeclarationCL: MethodDeclarationCL MethodDeclaration
#line 130 "parser.yy"
                                           {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 973 "parser.tab.cc"
    break;

  case 18: // MethodDeclaration: PUBLIC Type Identifier LP MethodDeclarationParamsOpt RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE
#line 136 "parser.yy"
                                                                                                                                           { 
                yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
               
          }
#line 987 "parser.tab.cc"
    break;

  case 19: // MethodDeclarationParamsOpt: %empty
#line 147 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationParamsOpt", "", yylineno); }
#line 993 "parser.tab.cc"
    break;

  case 20: // MethodDeclarationParamsOpt: MethodDeclarationParams
#line 148 "parser.yy"
                            {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationParamsOpt", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1002 "parser.tab.cc"
    break;

  case 21: // MethodDeclarationParams: Parameter
#line 154 "parser.yy"
             { yylhs.value.as < Node * > () = new Node("ParameterList", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1008 "parser.tab.cc"
    break;

  case 22: // MethodDeclarationParams: MethodDeclarationParams COMMA Parameter
#line 155 "parser.yy"
                                            { 
          yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > (); 
          yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
      }
#line 1017 "parser.tab.cc"
    break;

  case 23: // Parameter: Type Identifier
#line 163 "parser.yy"
                    {
         yylhs.value.as < Node * > () = new Node("Parameter", "", yylineno);
         yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
         yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1027 "parser.tab.cc"
    break;

  case 24: // MethodDeclarationBody: %empty
#line 172 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno); }
#line 1033 "parser.tab.cc"
    break;

  case 25: // MethodDeclarationBody: VarDeclaration
#line 173 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1042 "parser.tab.cc"
    break;

  case 26: // MethodDeclarationBody: Statement
#line 177 "parser.yy"
               {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1051 "parser.tab.cc"
    break;

  case 27: // MethodDeclarationBody: MethodDeclarationBody VarDeclaration
#line 181 "parser.yy"
                                          {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1060 "parser.tab.cc"
    break;

  case 28: // MethodDeclarationBody: MethodDeclarationBody Statement
#line 185 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1069 "parser.tab.cc"
    break;

  case 29: // VarDeclaration: Type Identifier SEMICOLON
#line 190 "parser.yy"
                                          { 
                yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1079 "parser.tab.cc"
    break;

  case 30: // Type: INT LBRACKET RBRACKET
#line 198 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("IntArray", "", yylineno); }
#line 1085 "parser.tab.cc"
    break;

  case 31: // Type: BOOLEAN
#line 199 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno); }
#line 1091 "parser.tab.cc"
    break;

  case 32: // Type: INT
#line 200 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Int", "", yylineno); }
#line 1097 "parser.tab.cc"
    break;

  case 33: // Type: Identifier
#line 201 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Identifier", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1103 "parser.tab.cc"
    break;

  case 34: // StatementMulti: %empty
#line 206 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno); }
#line 1109 "parser.tab.cc"
    break;

  case 35: // StatementMulti: Statement
#line 207 "parser.yy"
              {
        yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1118 "parser.tab.cc"
    break;

  case 36: // StatementMulti: StatementMulti Statement
#line 211 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1127 "parser.tab.cc"
    break;

  case 37: // Statement: LBRACE StatementMulti RBRACE
#line 218 "parser.yy"
                                        {
            yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        }
#line 1136 "parser.tab.cc"
    break;

  case 38: // Statement: IF LP expression RP Statement ELSE Statement
#line 222 "parser.yy"
                                                       { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1147 "parser.tab.cc"
    break;

  case 39: // Statement: IF LP expression RP Statement
#line 228 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1157 "parser.tab.cc"
    break;

  case 40: // Statement: WHILE LP expression RP Statement
#line 233 "parser.yy"
                                           { 
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1167 "parser.tab.cc"
    break;

  case 41: // Statement: SYSTEM_OUT_PRINTLN LP expression RP SEMICOLON
#line 238 "parser.yy"
                                                        { 
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1176 "parser.tab.cc"
    break;

  case 42: // Statement: Identifier ASSIGN expression SEMICOLON
#line 242 "parser.yy"
                                                 { 
                yylhs.value.as < Node * > () = new Node("AssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1186 "parser.tab.cc"
    break;

  case 43: // Statement: Identifier LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 247 "parser.yy"
                                                                              { 
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1197 "parser.tab.cc"
    break;

  case 44: // expression: expression PLUSOP expression
#line 254 "parser.yy"
                                         { 
                yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1207 "parser.tab.cc"
    break;

  case 45: // expression: expression MINUSOP expression
#line 259 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1217 "parser.tab.cc"
    break;

  case 46: // expression: expression MULTOP expression
#line 264 "parser.yy"
                                       { 
                yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1227 "parser.tab.cc"
    break;

  case 47: // expression: expression AND expression
#line 269 "parser.yy"
                                    { 
                yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1237 "parser.tab.cc"
    break;

  case 48: // expression: expression OR expression
#line 274 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1247 "parser.tab.cc"
    break;

  case 49: // expression: expression LT expression
#line 279 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("LtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1257 "parser.tab.cc"
    break;

  case 50: // expression: expression GT expression
#line 284 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("GtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1267 "parser.tab.cc"
    break;

  case 51: // expression: expression EQ expression
#line 289 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("EqExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1277 "parser.tab.cc"
    break;

  case 52: // expression: expression LBRACKET expression RBRACKET
#line 295 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1287 "parser.tab.cc"
    break;

  case 53: // expression: expression DOT LENGTH
#line 301 "parser.yy"
                                {
                yylhs.value.as < Node * > () = new Node("ArrayLength", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1296 "parser.tab.cc"
    break;

  case 54: // expression: expression DOT Identifier LP ExpressionParamsOpt RP
#line 305 "parser.yy"
                                                              {
                yylhs.value.as < Node * > () = new Node("MethodCall","", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              
            }
#line 1308 "parser.tab.cc"
    break;

  case 55: // expression: TRUE
#line 313 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "true", yylineno); }
#line 1314 "parser.tab.cc"
    break;

  case 56: // expression: FALSE
#line 314 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "false", yylineno); }
#line 1320 "parser.tab.cc"
    break;

  case 57: // expression: Identifier
#line 315 "parser.yy"
                     { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1326 "parser.tab.cc"
    break;

  case 58: // expression: THIS
#line 316 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 1332 "parser.tab.cc"
    break;

  case 59: // expression: NEW INT LBRACKET expression RBRACKET
#line 317 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("NewArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 1338 "parser.tab.cc"
    break;

  case 60: // expression: NEW Identifier LP RP
#line 318 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("NewObjectExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); }
#line 1344 "parser.tab.cc"
    break;

  case 61: // expression: NOT expression
#line 319 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1350 "parser.tab.cc"
    break;

  case 62: // expression: LP expression RP
#line 320 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("Expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1356 "parser.tab.cc"
    break;

  case 63: // expression: factor
#line 321 "parser.yy"
                  { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1362 "parser.tab.cc"
    break;

  case 64: // ExpressionParamsOpt: %empty
#line 327 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("ExpressionParamsOpt", "", yylineno); }
#line 1368 "parser.tab.cc"
    break;

  case 65: // ExpressionParamsOpt: ExpressionParams
#line 328 "parser.yy"
                              {
            yylhs.value.as < Node * > () = new Node("ExpressionParamsOpt", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1377 "parser.tab.cc"
    break;

  case 66: // ExpressionParams: expression
#line 334 "parser.yy"
                      {
            yylhs.value.as < Node * > () = new Node("ExpressionParams", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1386 "parser.tab.cc"
    break;

  case 67: // ExpressionParams: ExpressionParams COMMA expression
#line 338 "parser.yy"
                                               {
            yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); 
            }
#line 1395 "parser.tab.cc"
    break;

  case 68: // factor: INT
#line 344 "parser.yy"
            { yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno); /* printf("r1 "); */}
#line 1401 "parser.tab.cc"
    break;

  case 69: // Identifier: IDENTIFIER
#line 347 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); /* printf("r7 "); */}
#line 1407 "parser.tab.cc"
    break;


#line 1411 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -46;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -13,    -9,    21,   -46,    35,   -22,   -46,   -46,   -22,    40,
     -46,   -46,    16,    44,   -46,   -46,    49,    -1,    65,    50,
     -46,    -4,   -46,   -22,   -46,    69,    55,    -1,    74,   -46,
     -46,    61,    77,   -46,   -22,   -46,   -46,   -46,   112,   114,
      99,    -1,    85,   119,    91,   -46,   -22,    97,   129,    -1,
     -46,   -22,   334,   -46,   136,    78,   138,   143,   148,   320,
     -46,   -46,     6,   153,    98,   -46,     6,   304,   304,   304,
     304,   -46,   -46,   304,   304,    78,   -46,   -46,   -46,   304,
     304,   -46,   -46,   -46,    -2,   182,   -46,   -46,   203,   219,
      62,   233,   127,    78,   247,    13,   125,   164,   304,   304,
     304,    78,   304,   304,   304,   304,   304,    38,   304,    78,
     137,   162,   -46,   163,   126,   -46,   -46,   304,   167,    19,
      19,    13,   150,   303,   289,     4,     4,    23,   -46,   181,
     144,   -46,   -46,   -46,   304,   179,   -46,   165,   -46,    78,
     304,   -46,   261,   -46,   -46,   -46,   275,   183,   155,   -46,
     -46,   304,   275
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     3,     0,     0,
       5,    69,     0,     0,     4,     6,     0,    12,     0,    32,
      31,    15,    13,     0,    33,     0,     0,     0,     0,    16,
      14,     0,     0,    30,     0,    11,    17,    29,     0,     0,
       0,    19,     0,     0,    20,    21,     0,     0,     0,     0,
      23,     0,    24,    22,     0,    34,     0,     0,     0,     0,
      25,    26,    33,     0,     0,    35,     0,     0,     0,     0,
       0,    27,    28,     0,     0,     0,    37,    36,    68,     0,
       0,    55,    56,    58,     0,     0,    63,    57,     0,     0,
       0,     0,     0,     8,     0,    61,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,     0,     0,     9,    62,     0,     0,    44,
      45,    46,    39,    47,    48,    49,    50,    51,    53,     0,
       0,    40,    41,    18,     0,     0,    10,     0,    60,     0,
      64,    52,     0,     7,    59,    38,    66,     0,    65,    43,
      54,     0,    67
  };

  const short
  parser::yypgoto_[] =
  {
     -46,   -46,   -46,   -46,   -46,   -46,   184,   -46,   -46,   171,
     -46,   -46,   151,   -46,   -20,    22,   -46,   -45,    12,   -46,
     -46,   -46,    -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     9,     4,   114,    10,    21,    28,    29,
      43,    44,    45,    59,    22,    23,    64,    61,    85,   147,
     148,    86,    87
  };

  const unsigned char
  parser::yytable_[] =
  {
      12,    30,    19,    13,    96,    19,     1,    98,    99,   100,
      65,     5,    24,    11,    72,    27,    24,    73,    31,    77,
      20,     6,    24,    20,   100,    16,    98,    99,   100,    39,
      93,    11,    60,    11,    11,     7,    24,   104,   105,    71,
      14,    50,   107,   108,    24,    74,    54,    62,   115,    34,
      66,   107,   108,    17,    62,     8,   122,   107,   108,    66,
       8,   107,   108,    46,   131,    98,    99,   100,    18,   136,
      66,    46,   128,    11,   102,   103,   104,   105,   106,    97,
      88,    89,    90,    25,    35,    91,    92,    55,    66,    26,
      32,    94,    95,    27,   145,    33,    66,    37,   111,    38,
     107,   108,   129,    56,    66,    57,    58,    55,    76,    66,
     119,   120,   121,    11,   123,   124,   125,   126,   127,    40,
     130,    41,    42,    56,    47,    57,    58,    48,    49,   137,
      98,    99,   100,    11,    66,    55,   135,    51,    52,   102,
     103,   104,   105,   106,    63,    67,   142,    98,    99,   100,
      68,    56,   146,    57,    58,    69,   102,   103,   104,   105,
     106,    11,    75,   152,   117,   107,   108,   113,    98,    99,
     100,   118,   133,   132,   134,   138,   139,   102,   103,   104,
     105,   106,   107,   108,   141,    98,    99,   100,   140,   143,
     101,   150,   151,    15,   102,   103,   104,   105,   106,    36,
      53,     0,     0,   107,   108,   144,    98,    99,   100,     0,
       0,   109,     0,     0,     0,   102,   103,   104,   105,   106,
     107,   108,    98,    99,   100,     0,     0,   110,     0,     0,
       0,   102,   103,   104,   105,   106,    98,    99,   100,     0,
       0,   107,   108,     0,     0,   102,   103,   104,   105,   106,
      98,    99,   100,     0,     0,   116,     0,   107,   108,   102,
     103,   104,   105,   106,    98,    99,   100,     0,     0,   112,
       0,   107,   108,   102,   103,   104,   105,   106,    98,    99,
     100,     0,     0,     0,     0,   107,   108,   102,   103,   104,
     105,   106,    98,    99,   100,     0,     0,   149,     0,   107,
     108,   102,     0,   104,   105,   106,    98,    99,   100,     0,
      78,    79,     0,   107,   108,     0,     0,   104,   105,   106,
       0,    80,     0,     0,     0,     0,    19,   107,   108,    55,
       0,     0,     0,     0,    81,    82,    83,    84,     0,    11,
      19,   107,   108,    55,    20,    56,     0,    57,    58,    70,
       0,     0,     0,     0,     0,    11,     0,     0,    20,    56,
       0,    57,    58,     0,     0,     0,     0,     0,     0,    11
  };

  const short
  parser::yycheck_[] =
  {
       5,    21,     6,     8,     6,     6,    19,     3,     4,     5,
      55,    20,    17,    35,    59,    19,    21,    11,    23,    64,
      24,     0,    27,    24,     5,     9,     3,     4,     5,    34,
      75,    35,    52,    35,    35,     0,    41,    14,    15,    59,
       0,    46,    38,    39,    49,    39,    51,    52,    93,    27,
      55,    38,    39,     9,    59,    20,   101,    38,    39,    64,
      20,    38,    39,    41,   109,     3,     4,     5,    19,   114,
      75,    49,    34,    35,    12,    13,    14,    15,    16,    84,
      68,    69,    70,    18,    10,    73,    74,     9,    93,    39,
      21,    79,    80,    19,   139,    40,   101,    36,    36,    22,
      38,    39,   107,    25,   109,    27,    28,     9,    10,   114,
      98,    99,   100,    35,   102,   103,   104,   105,   106,     7,
     108,     7,    23,    25,    39,    27,    28,     8,    37,   117,
       3,     4,     5,    35,   139,     9,    10,    40,     9,    12,
      13,    14,    15,    16,     8,     7,   134,     3,     4,     5,
       7,    25,   140,    27,    28,     7,    12,    13,    14,    15,
      16,    35,     9,   151,    39,    38,    39,    40,     3,     4,
       5,     7,    10,    36,    11,     8,    26,    12,    13,    14,
      15,    16,    38,    39,    40,     3,     4,     5,     7,    10,
       8,     8,    37,     9,    12,    13,    14,    15,    16,    28,
      49,    -1,    -1,    38,    39,    40,     3,     4,     5,    -1,
      -1,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      38,    39,     3,     4,     5,    -1,    -1,     8,    -1,    -1,
      -1,    12,    13,    14,    15,    16,     3,     4,     5,    -1,
      -1,    38,    39,    -1,    -1,    12,    13,    14,    15,    16,
       3,     4,     5,    -1,    -1,     8,    -1,    38,    39,    12,
      13,    14,    15,    16,     3,     4,     5,    -1,    -1,    36,
      -1,    38,    39,    12,    13,    14,    15,    16,     3,     4,
       5,    -1,    -1,    -1,    -1,    38,    39,    12,    13,    14,
      15,    16,     3,     4,     5,    -1,    -1,    36,    -1,    38,
      39,    12,    -1,    14,    15,    16,     3,     4,     5,    -1,
       6,     7,    -1,    38,    39,    -1,    -1,    14,    15,    16,
      -1,    17,    -1,    -1,    -1,    -1,     6,    38,    39,     9,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    -1,    35,
       6,    38,    39,     9,    24,    25,    -1,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    24,    25,
      -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,    19,    42,    43,    45,    20,     0,     0,    20,    44,
      47,    35,    63,    63,     0,    47,     9,     9,    19,     6,
      24,    48,    55,    56,    63,    18,    39,    19,    49,    50,
      55,    63,    21,    40,    56,    10,    50,    36,    22,    63,
       7,     7,    23,    51,    52,    53,    56,    39,     8,    37,
      63,    40,     9,    53,    63,     9,    25,    27,    28,    54,
      55,    58,    63,     8,    57,    58,    63,     7,     7,     7,
      29,    55,    58,    11,    39,     9,    10,    58,     6,     7,
      17,    30,    31,    32,    33,    59,    62,    63,    59,    59,
      59,    59,    59,    58,    59,    59,     6,    63,     3,     4,
       5,     8,    12,    13,    14,    15,    16,    38,    39,     8,
       8,    36,    36,    40,    46,    58,     8,    39,     7,    59,
      59,    59,    58,    59,    59,    59,    59,    59,    34,    63,
      59,    58,    36,    10,    11,    10,    58,    59,     8,    26,
       7,    40,    59,    10,    40,    58,    59,    60,    61,    36,
       8,    37,    59
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    47,    48,    48,    48,    49,    49,    49,    50,    51,
      51,    52,    52,    53,    54,    54,    54,    54,    54,    55,
      56,    56,    56,    56,    57,    57,    57,    58,    58,    58,
      58,    58,    58,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    62,    63
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     1,     2,    19,     0,     1,
       2,     6,     0,     1,     2,     0,     1,     2,    12,     0,
       1,     1,     3,     2,     0,     1,     1,     2,     2,     3,
       3,     1,     1,     1,     0,     1,     2,     3,     7,     5,
       5,     5,     4,     7,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     3,     6,     1,     1,     1,     1,     5,
       4,     2,     3,     1,     0,     1,     1,     3,     1,     1
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
  "Goal", "ClassDeclarationList", "MainClass", "StatementListM",
  "ClassDeclaration", "VarDeclarationCL", "MethodDeclarationCL",
  "MethodDeclaration", "MethodDeclarationParamsOpt",
  "MethodDeclarationParams", "Parameter", "MethodDeclarationBody",
  "VarDeclaration", "Type", "StatementMulti", "Statement", "expression",
  "ExpressionParamsOpt", "ExpressionParams", "factor", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    54,    54,    59,    64,    71,    75,    81,    93,    94,
      98,   105,   114,   115,   119,   125,   126,   130,   136,   147,
     148,   154,   155,   163,   172,   173,   177,   181,   185,   190,
     198,   199,   200,   201,   206,   207,   211,   218,   222,   228,
     233,   238,   242,   247,   254,   259,   264,   269,   274,   279,
     284,   289,   295,   301,   305,   313,   314,   315,   316,   317,
     318,   319,   320,   321,   327,   328,   334,   338,   344,   347
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
#line 2015 "parser.tab.cc"

#line 351 "parser.yy"
