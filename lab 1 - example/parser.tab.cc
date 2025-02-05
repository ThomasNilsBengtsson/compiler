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
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MethodDeclarationParams: // MethodDeclarationParams
      case symbol_kind::S_MethodDeclarationBody: // MethodDeclarationBody
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_StatementMulti: // StatementMulti
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
#line 41 "parser.yy"
                {root = yylhs.value.as < Node * > ();}
#line 823 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass "END of FILE"
#line 46 "parser.yy"
               {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* Måste kanske sätta root som root = $$ */                  
  }
#line 831 "parser.tab.cc"
    break;

  case 4: // Goal: MainClass ClassDeclarationList "END of FILE"
#line 49 "parser.yy"
                                      {
      yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 840 "parser.tab.cc"
    break;

  case 5: // ClassDeclarationList: ClassDeclaration
#line 55 "parser.yy"
                     {
      yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
      yylhs.value.as < Node * > () -> children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 849 "parser.tab.cc"
    break;

  case 6: // ClassDeclarationList: ClassDeclarationList ClassDeclaration
#line 59 "parser.yy"
                                           {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 858 "parser.tab.cc"
    break;

  case 7: // MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement StatementListM RBRACE RBRACE
#line 65 "parser.yy"
                                                                                                                                                          { 
                yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);
               /*  $$->children.push_back(new Node("Identifier", $3, yylineno));   vet inte ska man ha detta*/
               yylhs.value.as < Node * > ()->children.push_back(yystack_[16].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());

          }
#line 871 "parser.tab.cc"
    break;

  case 8: // StatementListM: Statement
#line 76 "parser.yy"
             {
        yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 880 "parser.tab.cc"
    break;

  case 9: // StatementListM: StatementListM Statement
#line 80 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 889 "parser.tab.cc"
    break;

  case 10: // ClassDeclaration: CLASS Identifier LBRACE VarDeclarationCL MethodDeclarationCL RBRACE
#line 87 "parser.yy"
                                                                                      { 
            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
      }
#line 898 "parser.tab.cc"
    break;

  case 11: // VarDeclarationCL: VarDeclaration
#line 94 "parser.yy"
                  {
        yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 907 "parser.tab.cc"
    break;

  case 12: // VarDeclarationCL: VarDeclarationCL VarDeclaration
#line 98 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 916 "parser.tab.cc"
    break;

  case 13: // MethodDeclarationCL: MethodDeclaration
#line 104 "parser.yy"
                     {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 925 "parser.tab.cc"
    break;

  case 14: // MethodDeclarationCL: MethodDeclarationCL MethodDeclaration
#line 108 "parser.yy"
                                           {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 934 "parser.tab.cc"
    break;

  case 15: // MethodDeclaration: PUBLIC Type Identifier LP MethodDeclarationParams RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE
#line 114 "parser.yy"
                                                                                                                                        { 
                yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
               
          }
#line 948 "parser.tab.cc"
    break;

  case 16: // MethodDeclarationParams: Type Identifier
#line 125 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationParams", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 958 "parser.tab.cc"
    break;

  case 17: // MethodDeclarationParams: MethodDeclarationParams COMMA Type Identifier
#line 130 "parser.yy"
                                                   {
        yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 968 "parser.tab.cc"
    break;

  case 18: // MethodDeclarationBody: VarDeclaration
#line 137 "parser.yy"
                  {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 977 "parser.tab.cc"
    break;

  case 19: // MethodDeclarationBody: Statement
#line 141 "parser.yy"
               {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 986 "parser.tab.cc"
    break;

  case 20: // MethodDeclarationBody: MethodDeclarationBody VarDeclaration
#line 145 "parser.yy"
                                          {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 995 "parser.tab.cc"
    break;

  case 21: // MethodDeclarationBody: MethodDeclarationBody Statement
#line 149 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1004 "parser.tab.cc"
    break;

  case 22: // VarDeclaration: Type Identifier SEMICOLON
#line 154 "parser.yy"
                                          { 
                yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1014 "parser.tab.cc"
    break;

  case 23: // Type: INT LBRACKET RBRACKET
#line 162 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("IntArray", "", yylineno); }
#line 1020 "parser.tab.cc"
    break;

  case 24: // Type: BOOLEAN
#line 163 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno); }
#line 1026 "parser.tab.cc"
    break;

  case 25: // Type: INT
#line 164 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Int", "", yylineno); }
#line 1032 "parser.tab.cc"
    break;

  case 26: // Type: IDENTIFIER
#line 165 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); }
#line 1038 "parser.tab.cc"
    break;

  case 27: // StatementMulti: Statement
#line 170 "parser.yy"
             {
        yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1047 "parser.tab.cc"
    break;

  case 28: // StatementMulti: StatementMulti Statement
#line 174 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1056 "parser.tab.cc"
    break;

  case 29: // Statement: LBRACE StatementMulti RBRACE
#line 179 "parser.yy"
                                        {
            yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
        }
#line 1064 "parser.tab.cc"
    break;

  case 30: // Statement: IF LP expression RP Statement ELSE Statement
#line 182 "parser.yy"
                                                       { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1075 "parser.tab.cc"
    break;

  case 31: // Statement: WHILE LP expression RP Statement
#line 188 "parser.yy"
                                           { 
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1085 "parser.tab.cc"
    break;

  case 32: // Statement: SYSTEM_OUT_PRINTLN LP expression RP SEMICOLON
#line 193 "parser.yy"
                                                        { 
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1094 "parser.tab.cc"
    break;

  case 33: // Statement: Identifier ASSIGN expression SEMICOLON
#line 197 "parser.yy"
                                                 { 
                yylhs.value.as < Node * > () = new Node("AssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1104 "parser.tab.cc"
    break;

  case 34: // Statement: Identifier LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 202 "parser.yy"
                                                                              { 
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1115 "parser.tab.cc"
    break;

  case 35: // expression: expression PLUSOP expression
#line 209 "parser.yy"
                                         { 
                yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1125 "parser.tab.cc"
    break;

  case 36: // expression: expression MINUSOP expression
#line 214 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1135 "parser.tab.cc"
    break;

  case 37: // expression: expression MULTOP expression
#line 219 "parser.yy"
                                       { 
                yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1145 "parser.tab.cc"
    break;

  case 38: // expression: expression AND expression
#line 224 "parser.yy"
                                    { 
                yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1155 "parser.tab.cc"
    break;

  case 39: // expression: expression OR expression
#line 229 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1165 "parser.tab.cc"
    break;

  case 40: // expression: expression LT expression
#line 234 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("LtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1175 "parser.tab.cc"
    break;

  case 41: // expression: expression GT expression
#line 239 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("GtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1185 "parser.tab.cc"
    break;

  case 42: // expression: expression EQ expression
#line 244 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("EqExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1195 "parser.tab.cc"
    break;

  case 43: // expression: expression LBRACKET expression RBRACKET
#line 265 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1205 "parser.tab.cc"
    break;

  case 44: // expression: expression DOT Identifier LP ExpressionParams RP
#line 270 "parser.yy"
                                                           {
                yylhs.value.as < Node * > () = new Node("MethodCall","", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
              
            }
#line 1215 "parser.tab.cc"
    break;

  case 45: // expression: INT
#line 275 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno); }
#line 1221 "parser.tab.cc"
    break;

  case 46: // expression: TRUE
#line 276 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "true", yylineno); }
#line 1227 "parser.tab.cc"
    break;

  case 47: // expression: FALSE
#line 277 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "false", yylineno); }
#line 1233 "parser.tab.cc"
    break;

  case 48: // expression: Identifier
#line 278 "parser.yy"
                     { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1239 "parser.tab.cc"
    break;

  case 49: // expression: THIS
#line 279 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 1245 "parser.tab.cc"
    break;

  case 50: // expression: NEW INT LBRACKET expression RBRACKET
#line 280 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("NewArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 1251 "parser.tab.cc"
    break;

  case 51: // expression: NOT expression
#line 282 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1257 "parser.tab.cc"
    break;

  case 52: // expression: factor
#line 284 "parser.yy"
                 { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1263 "parser.tab.cc"
    break;

  case 53: // ExpressionParams: expression
#line 289 "parser.yy"
                      {
            yylhs.value.as < Node * > () = new Node("ExpressionParams", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1272 "parser.tab.cc"
    break;

  case 54: // ExpressionParams: ExpressionParams COMMA expression
#line 293 "parser.yy"
                                               {
            yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1281 "parser.tab.cc"
    break;

  case 55: // factor: INT
#line 298 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1287 "parser.tab.cc"
    break;

  case 56: // factor: LP expression RP
#line 299 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 1293 "parser.tab.cc"
    break;

  case 57: // Identifier: IDENTIFIER
#line 304 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); /* printf("r7 "); */}
#line 1299 "parser.tab.cc"
    break;


#line 1303 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -53;

  const signed char parser::yytable_ninf_ = -27;

  const short
  parser::yypact_[] =
  {
     -15,   -10,    17,   -53,    56,   -30,   -53,   -53,   -30,    66,
     -53,   -53,     2,    45,   -53,   -53,    39,    71,    46,   -19,
     -53,   -53,    69,   -53,   -30,    44,    27,    71,    33,   -53,
     -53,    32,    61,   -53,   -30,   -53,   -53,   -53,    82,    85,
      55,    71,    60,     5,   -30,    63,    92,    71,   -53,   -30,
     300,   -30,    97,   186,   104,   110,   112,    86,   294,   -53,
     -53,    -2,   -53,   111,   128,   -53,     1,     1,     1,     1,
     -53,   -53,     1,     1,   186,   -53,   -53,   -53,     1,     1,
     -53,   -53,   -53,   116,   136,   -53,   -53,   164,   178,   184,
     221,    11,   186,   235,   263,    87,     1,     1,     1,   186,
       1,     1,     1,     1,     1,   -30,     1,   186,    94,   118,
     -53,   132,   285,   -53,   -53,     1,   277,   277,   192,   105,
     263,   263,   263,   263,   263,   138,    58,   -53,   -53,   -53,
       1,   144,   -53,   120,   186,     1,   -53,   249,   -53,   -53,
     -53,   263,    20,   -53,   -53,     1,   263
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     3,     0,     0,
       5,    57,     0,     0,     4,     6,     0,     0,     0,    25,
      24,    26,     0,    11,     0,     0,     0,     0,     0,    13,
      12,     0,     0,    23,     0,    10,    14,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,     0,     0,     0,     0,     0,     0,    57,     0,    18,
      19,     0,    17,     0,     0,    27,     0,     0,     0,     0,
      20,    21,     0,     0,     0,    29,    28,    45,     0,     0,
      46,    47,    49,     0,     0,    52,    48,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     8,    56,     0,    35,    36,    37,     0,
      38,    39,    40,    41,    42,     0,     0,    31,    32,    15,
       0,     0,     9,     0,     0,     0,    43,     0,     7,    50,
      30,    53,     0,    34,    44,     0,    54
  };

  const short
  parser::yypgoto_[] =
  {
     -53,   -53,   -53,   -53,   -53,   -53,   137,   -53,   -53,   133,
     -53,   -53,   -20,    -6,   -53,   -52,    12,   -53,   -53,    -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     9,     4,   112,    10,    22,    28,    29,
      43,    58,    23,    24,    64,    60,    84,   142,    85,    86
  };

  const short
  parser::yytable_[] =
  {
      12,    65,    30,    13,     1,    11,    71,    77,    78,    72,
       5,    16,    76,    46,    96,    97,    98,     6,    79,    31,
      26,    34,    92,   100,   101,   102,   103,   104,   144,    39,
      59,    80,    81,    82,    83,    44,    11,    73,    70,    48,
     113,    51,    47,    35,    52,    61,    62,   119,    61,   105,
     106,   111,    27,    61,    17,   127,     7,   145,    18,    61,
     132,    96,    97,    98,    25,    32,    14,    33,    37,    61,
     100,   101,   102,   103,   104,    19,     8,    19,    42,    87,
      88,    89,   140,    38,    90,    91,     8,    61,    27,    40,
      93,    94,    41,    20,    61,    20,   105,   106,   136,    45,
     125,    50,    61,    49,    21,    63,    21,    61,   116,   117,
     118,    66,   120,   121,   122,   123,   124,    67,   126,    68,
      74,   -26,    95,    96,    97,    98,   115,   133,   129,    61,
     128,   134,   100,   101,   102,   103,   104,    53,    75,    96,
      97,    98,   137,   130,    99,   135,    15,   141,   100,   101,
     102,   103,   104,    54,   138,    55,    56,   146,   105,   106,
     139,    36,     0,    11,     0,     0,     0,    96,    97,    98,
       0,     0,   107,     0,   105,   106,   100,   101,   102,   103,
     104,    96,    97,    98,     0,     0,   108,    96,    97,    98,
     100,   101,   102,   103,   104,    53,   100,   101,   102,   103,
     104,     0,   105,   106,   100,   101,   102,   103,   104,     0,
       0,    54,     0,    55,    56,     0,   105,   106,     0,     0,
     109,    11,   105,   106,    96,    97,    98,     0,     0,     0,
     105,   106,     0,   100,   101,   102,   103,   104,    96,    97,
      98,     0,     0,   114,     0,     0,     0,   100,   101,   102,
     103,   104,    96,    97,    98,     0,     0,   110,     0,   105,
     106,   100,   101,   102,   103,   104,    96,    97,    98,     0,
       0,     0,     0,   105,   106,   100,   101,   102,   103,   104,
       0,     0,    98,     0,     0,   143,     0,   105,   106,   100,
     101,   102,   103,   104,    53,   131,     0,     0,     0,     0,
      19,   105,   106,    53,     0,     0,    19,     0,     0,    53,
      54,     0,    55,    56,     0,   105,   106,     0,    20,    54,
      11,    55,    56,    69,    20,    54,     0,    55,    56,    57,
       0,     0,     0,     0,     0,    57
  };

  const short
  parser::yycheck_[] =
  {
       5,    53,    22,     8,    19,    35,    58,     6,     7,    11,
      20,     9,    64,     8,     3,     4,     5,     0,    17,    24,
      39,    27,    74,    12,    13,    14,    15,    16,     8,    34,
      50,    30,    31,    32,    33,    41,    35,    39,    58,    44,
      92,    47,    37,    10,    49,    50,    51,    99,    53,    38,
      39,    40,    19,    58,     9,   107,     0,    37,    19,    64,
     112,     3,     4,     5,    18,    21,     0,    40,    36,    74,
      12,    13,    14,    15,    16,     6,    20,     6,    23,    67,
      68,    69,   134,    22,    72,    73,    20,    92,    19,     7,
      78,    79,     7,    24,    99,    24,    38,    39,    40,    39,
     105,     9,   107,    40,    35,     8,    35,   112,    96,    97,
      98,     7,   100,   101,   102,   103,   104,     7,   106,     7,
       9,    35,     6,     3,     4,     5,    39,   115,    10,   134,
      36,    26,    12,    13,    14,    15,    16,     9,    10,     3,
       4,     5,   130,    11,     8,     7,     9,   135,    12,    13,
      14,    15,    16,    25,    10,    27,    28,   145,    38,    39,
      40,    28,    -1,    35,    -1,    -1,    -1,     3,     4,     5,
      -1,    -1,     8,    -1,    38,    39,    12,    13,    14,    15,
      16,     3,     4,     5,    -1,    -1,     8,     3,     4,     5,
      12,    13,    14,    15,    16,     9,    12,    13,    14,    15,
      16,    -1,    38,    39,    12,    13,    14,    15,    16,    -1,
      -1,    25,    -1,    27,    28,    -1,    38,    39,    -1,    -1,
      36,    35,    38,    39,     3,     4,     5,    -1,    -1,    -1,
      38,    39,    -1,    12,    13,    14,    15,    16,     3,     4,
       5,    -1,    -1,     8,    -1,    -1,    -1,    12,    13,    14,
      15,    16,     3,     4,     5,    -1,    -1,    36,    -1,    38,
      39,    12,    13,    14,    15,    16,     3,     4,     5,    -1,
      -1,    -1,    -1,    38,    39,    12,    13,    14,    15,    16,
      -1,    -1,     5,    -1,    -1,    36,    -1,    38,    39,    12,
      13,    14,    15,    16,     9,    10,    -1,    -1,    -1,    -1,
       6,    38,    39,     9,    -1,    -1,     6,    -1,    -1,     9,
      25,    -1,    27,    28,    -1,    38,    39,    -1,    24,    25,
      35,    27,    28,    29,    24,    25,    -1,    27,    28,    35,
      -1,    -1,    -1,    -1,    -1,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,    19,    42,    43,    45,    20,     0,     0,    20,    44,
      47,    35,    60,    60,     0,    47,     9,     9,    19,     6,
      24,    35,    48,    53,    54,    18,    39,    19,    49,    50,
      53,    60,    21,    40,    54,    10,    50,    36,    22,    60,
       7,     7,    23,    51,    54,    39,     8,    37,    60,    40,
       9,    54,    60,     9,    25,    27,    28,    35,    52,    53,
      56,    60,    60,     8,    55,    56,     7,     7,     7,    29,
      53,    56,    11,    39,     9,    10,    56,     6,     7,    17,
      30,    31,    32,    33,    57,    59,    60,    57,    57,    57,
      57,    57,    56,    57,    57,     6,     3,     4,     5,     8,
      12,    13,    14,    15,    16,    38,    39,     8,     8,    36,
      36,    40,    46,    56,     8,    39,    57,    57,    57,    56,
      57,    57,    57,    57,    57,    60,    57,    56,    36,    10,
      11,    10,    56,    57,    26,     7,    40,    57,    10,    40,
      56,    57,    58,    36,     8,    37,    57
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      47,    48,    48,    49,    49,    50,    51,    51,    52,    52,
      52,    52,    53,    54,    54,    54,    54,    55,    55,    56,
      56,    56,    56,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    59,    59,    60
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     1,     2,    19,     1,     2,
       6,     1,     2,     1,     2,    12,     2,     4,     1,     1,
       2,     2,     3,     3,     1,     1,     1,     1,     2,     3,
       7,     5,     5,     4,     7,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     6,     1,     1,     1,     1,     1,
       5,     2,     1,     1,     3,     1,     3,     1
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
  "MethodDeclaration", "MethodDeclarationParams", "MethodDeclarationBody",
  "VarDeclaration", "Type", "StatementMulti", "Statement", "expression",
  "ExpressionParams", "factor", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    41,    41,    46,    49,    55,    59,    65,    76,    80,
      87,    94,    98,   104,   108,   114,   125,   130,   137,   141,
     145,   149,   154,   162,   163,   164,   165,   170,   174,   179,
     182,   188,   193,   197,   202,   209,   214,   219,   224,   229,
     234,   239,   244,   265,   270,   275,   276,   277,   278,   279,
     280,   282,   284,   289,   293,   298,   299,   304
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
#line 1892 "parser.tab.cc"

#line 308 "parser.yy"
