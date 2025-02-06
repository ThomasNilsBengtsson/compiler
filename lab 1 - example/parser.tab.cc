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
                {root = yylhs.value.as < Node * > ();}
#line 818 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass "END of FILE"
#line 59 "parser.yy"
               {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* Måste kanske sätta root som root = $$ */                  
  }
#line 826 "parser.tab.cc"
    break;

  case 4: // Goal: MainClass ClassDeclarationList "END of FILE"
#line 62 "parser.yy"
                                      {
      yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
  }
#line 835 "parser.tab.cc"
    break;

  case 5: // ClassDeclarationList: ClassDeclaration
#line 68 "parser.yy"
                     {
      yylhs.value.as < Node * > () = new Node("ClassDeclarationList", "", yylineno);
      yylhs.value.as < Node * > () -> children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 844 "parser.tab.cc"
    break;

  case 6: // ClassDeclarationList: ClassDeclarationList ClassDeclaration
#line 72 "parser.yy"
                                           {
      yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
      yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 853 "parser.tab.cc"
    break;

  case 7: // MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement StatementListM RBRACE RBRACE
#line 78 "parser.yy"
                                                                                                                                                          { 
                yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);

               yylhs.value.as < Node * > ()->children.push_back(yystack_[16].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());

          }
#line 867 "parser.tab.cc"
    break;

  case 8: // StatementListM: %empty
#line 90 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno); }
#line 873 "parser.tab.cc"
    break;

  case 9: // StatementListM: Statement
#line 91 "parser.yy"
              {
        yylhs.value.as < Node * > () = new Node("StatementList", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 882 "parser.tab.cc"
    break;

  case 10: // StatementListM: StatementListM Statement
#line 95 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 891 "parser.tab.cc"
    break;

  case 11: // ClassDeclaration: CLASS Identifier LBRACE VarDeclarationCL MethodDeclarationCL RBRACE
#line 102 "parser.yy"
                                                                                      { 
            yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
      }
#line 902 "parser.tab.cc"
    break;

  case 12: // VarDeclarationCL: %empty
#line 111 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno); }
#line 908 "parser.tab.cc"
    break;

  case 13: // VarDeclarationCL: VarDeclaration
#line 112 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("VarDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 917 "parser.tab.cc"
    break;

  case 14: // VarDeclarationCL: VarDeclarationCL VarDeclaration
#line 116 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 926 "parser.tab.cc"
    break;

  case 15: // MethodDeclarationCL: %empty
#line 122 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno); }
#line 932 "parser.tab.cc"
    break;

  case 16: // MethodDeclarationCL: MethodDeclaration
#line 123 "parser.yy"
                      {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationCL", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 941 "parser.tab.cc"
    break;

  case 17: // MethodDeclarationCL: MethodDeclarationCL MethodDeclaration
#line 127 "parser.yy"
                                           {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 950 "parser.tab.cc"
    break;

  case 18: // MethodDeclaration: PUBLIC Type Identifier LP MethodDeclarationParams RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE
#line 133 "parser.yy"
                                                                                                                                        { 
                yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[10].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[7].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
               
          }
#line 964 "parser.tab.cc"
    break;

  case 19: // MethodDeclaration: PUBLIC Type Identifier LP RP LBRACE MethodDeclarationBody RETURN expression SEMICOLON RBRACE
#line 142 "parser.yy"
                                                                                                         { 
                yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 976 "parser.tab.cc"
    break;

  case 20: // MethodDeclarationParams: COMMA Type Identifier
#line 151 "parser.yy"
                         {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationParams", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 986 "parser.tab.cc"
    break;

  case 21: // MethodDeclarationParams: MethodDeclarationParams COMMA Type Identifier
#line 156 "parser.yy"
                                                   {
        yylhs.value.as < Node * > () = yystack_[3].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 996 "parser.tab.cc"
    break;

  case 22: // MethodDeclarationBody: %empty
#line 163 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno); }
#line 1002 "parser.tab.cc"
    break;

  case 23: // MethodDeclarationBody: VarDeclaration
#line 164 "parser.yy"
                   {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1011 "parser.tab.cc"
    break;

  case 24: // MethodDeclarationBody: Statement
#line 168 "parser.yy"
               {
        yylhs.value.as < Node * > () = new Node("MethodDeclarationBody", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1020 "parser.tab.cc"
    break;

  case 25: // MethodDeclarationBody: MethodDeclarationBody VarDeclaration
#line 172 "parser.yy"
                                          {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1029 "parser.tab.cc"
    break;

  case 26: // MethodDeclarationBody: MethodDeclarationBody Statement
#line 176 "parser.yy"
                                     {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1038 "parser.tab.cc"
    break;

  case 27: // MethodDeclarationBody: MethodDeclarationBody VarDeclaration Statement
#line 180 "parser.yy"
                                                    {
        yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1048 "parser.tab.cc"
    break;

  case 28: // VarDeclaration: Type Identifier SEMICOLON
#line 186 "parser.yy"
                                          { 
                yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1058 "parser.tab.cc"
    break;

  case 29: // Type: INT LBRACKET RBRACKET
#line 194 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("IntArray", "", yylineno); }
#line 1064 "parser.tab.cc"
    break;

  case 30: // Type: BOOLEAN
#line 195 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno); }
#line 1070 "parser.tab.cc"
    break;

  case 31: // Type: INT
#line 196 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Int", "", yylineno); }
#line 1076 "parser.tab.cc"
    break;

  case 32: // Type: Identifier
#line 197 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Identifier", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1082 "parser.tab.cc"
    break;

  case 33: // StatementMulti: %empty
#line 202 "parser.yy"
    { yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno); }
#line 1088 "parser.tab.cc"
    break;

  case 34: // StatementMulti: Statement
#line 203 "parser.yy"
              {
        yylhs.value.as < Node * > () = new Node("StatementMulti", "", yylineno);
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1097 "parser.tab.cc"
    break;

  case 35: // StatementMulti: StatementMulti Statement
#line 207 "parser.yy"
                              {
        yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > ();
        yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
    }
#line 1106 "parser.tab.cc"
    break;

  case 36: // Statement: LBRACE StatementMulti RBRACE
#line 214 "parser.yy"
                                        {
            yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
        }
#line 1115 "parser.tab.cc"
    break;

  case 37: // Statement: IF LP expression RP Statement ELSE Statement
#line 218 "parser.yy"
                                                       { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1126 "parser.tab.cc"
    break;

  case 38: // Statement: WHILE LP expression RP Statement
#line 224 "parser.yy"
                                           { 
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1136 "parser.tab.cc"
    break;

  case 39: // Statement: SYSTEM_OUT_PRINTLN LP expression RP SEMICOLON
#line 229 "parser.yy"
                                                        { 
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1145 "parser.tab.cc"
    break;

  case 40: // Statement: SYSTEM_OUT_PRINTLN LP error RP SEMICOLON
#line 233 "parser.yy"
                                                   { 
      yylhs.value.as < Node * > () = new Node("PrintStatement", "Error in print expression", yylineno);
      yyerrok; 
}
#line 1154 "parser.tab.cc"
    break;

  case 41: // Statement: Identifier ASSIGN expression SEMICOLON
#line 238 "parser.yy"
                                                 { 
                yylhs.value.as < Node * > () = new Node("AssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1164 "parser.tab.cc"
    break;

  case 42: // Statement: Identifier LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 243 "parser.yy"
                                                                              { 
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1175 "parser.tab.cc"
    break;

  case 43: // expression: expression PLUSOP expression
#line 250 "parser.yy"
                                         { 
                yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1185 "parser.tab.cc"
    break;

  case 44: // expression: expression MINUSOP expression
#line 255 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1195 "parser.tab.cc"
    break;

  case 45: // expression: expression MULTOP expression
#line 260 "parser.yy"
                                       { 
                yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1205 "parser.tab.cc"
    break;

  case 46: // expression: expression AND expression
#line 265 "parser.yy"
                                    { 
                yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1215 "parser.tab.cc"
    break;

  case 47: // expression: expression OR expression
#line 270 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1225 "parser.tab.cc"
    break;

  case 48: // expression: expression LT expression
#line 275 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("LtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1235 "parser.tab.cc"
    break;

  case 49: // expression: expression GT expression
#line 280 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("GtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1245 "parser.tab.cc"
    break;

  case 50: // expression: expression EQ expression
#line 285 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("EqExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1255 "parser.tab.cc"
    break;

  case 51: // expression: expression LBRACKET expression RBRACKET
#line 291 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1265 "parser.tab.cc"
    break;

  case 52: // expression: expression DOT LENGTH
#line 297 "parser.yy"
                                {
                yylhs.value.as < Node * > () = new Node("ArrayLength", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 1274 "parser.tab.cc"
    break;

  case 53: // expression: expression DOT Identifier LP ExpressionParams RP
#line 301 "parser.yy"
                                                           {
                yylhs.value.as < Node * > () = new Node("MethodCall","", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[5].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
              
            }
#line 1286 "parser.tab.cc"
    break;

  case 54: // expression: INT
#line 308 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno); }
#line 1292 "parser.tab.cc"
    break;

  case 55: // expression: TRUE
#line 309 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "true", yylineno); }
#line 1298 "parser.tab.cc"
    break;

  case 56: // expression: FALSE
#line 310 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "false", yylineno); }
#line 1304 "parser.tab.cc"
    break;

  case 57: // expression: Identifier
#line 311 "parser.yy"
                     { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1310 "parser.tab.cc"
    break;

  case 58: // expression: THIS
#line 312 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 1316 "parser.tab.cc"
    break;

  case 59: // expression: NEW INT LBRACKET expression RBRACKET
#line 313 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("NewArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 1322 "parser.tab.cc"
    break;

  case 60: // expression: NEW Identifier LP RP
#line 314 "parser.yy"
                               { yylhs.value.as < Node * > () = new Node("NewObjectExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ()); }
#line 1328 "parser.tab.cc"
    break;

  case 61: // expression: NOT expression
#line 315 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1334 "parser.tab.cc"
    break;

  case 62: // expression: LP expression RP
#line 316 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("Expression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());}
#line 1340 "parser.tab.cc"
    break;

  case 63: // ExpressionParams: %empty
#line 322 "parser.yy"
            {yylhs.value.as < Node * > () = new Node("ExpressionParams", "", yylineno);}
#line 1346 "parser.tab.cc"
    break;

  case 64: // ExpressionParams: expression
#line 324 "parser.yy"
                       {
            yylhs.value.as < Node * > () = new Node("ExpressionParams", "", yylineno);
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1355 "parser.tab.cc"
    break;

  case 65: // ExpressionParams: ExpressionParams COMMA expression
#line 328 "parser.yy"
                                               {
            yylhs.value.as < Node * > () = yystack_[2].value.as < Node * > ();
            yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
            }
#line 1364 "parser.tab.cc"
    break;

  case 66: // Identifier: IDENTIFIER
#line 336 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); /* printf("r7 "); */}
#line 1370 "parser.tab.cc"
    break;


#line 1374 "parser.tab.cc"

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
     -15,   -14,    17,   -46,     8,   -25,   -46,   -46,   -25,    21,
     -46,   -46,    11,    45,   -46,   -46,     4,    26,    49,    38,
     -46,    34,   -46,   -25,   -46,    65,    62,    26,    66,   -46,
     -46,    67,    82,   -46,   -25,   -46,   -46,   -46,    98,   100,
      88,    -6,    80,   116,    26,    25,    89,   367,   -25,   131,
      26,   -25,   391,   132,   145,   146,   103,   -46,   -46,    16,
     -46,   367,   -25,   143,   376,   -46,    16,   335,   335,   327,
     335,   391,   -46,   335,   335,   355,   -46,   153,   -46,   -46,
     -46,   335,   335,   -46,   -46,   -46,    58,   187,   -46,   202,
     147,   216,   230,   -46,   244,   130,   335,   391,   259,    35,
     124,   157,   335,   335,   335,   391,   335,   335,   335,   335,
     335,    64,   335,   391,   129,   135,   156,   -46,   161,   273,
     391,   -46,   335,   167,    -4,    -4,    35,   154,    75,   315,
      33,    33,    10,   -46,   172,   144,   -46,   -46,   -46,   -46,
     335,   171,   387,   -46,   173,   -46,   391,   335,   -46,   287,
     -46,   183,   -46,   -46,   -46,   301,    57,   -46,   -46,   -46,
     335,   301
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     3,     0,     0,
       5,    66,     0,     0,     4,     6,     0,    12,     0,    31,
      30,    15,    13,     0,    32,     0,     0,     0,     0,    16,
      14,     0,     0,    29,     0,    11,    17,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,    33,     0,     0,     0,     0,    23,    24,    32,
      20,    22,     0,     0,     0,    34,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    21,     0,    36,    35,
      54,     0,     0,    55,    56,    58,     0,     0,    57,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,    61,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       8,    62,     0,     0,    43,    44,    45,     0,    46,    47,
      48,    49,    50,    52,     0,     0,    38,    40,    39,    19,
       0,     0,     0,     9,     0,    60,     0,    63,    51,     0,
      18,     0,    10,    59,    37,    64,     0,    42,     7,    53,
       0,    65
  };

  const short
  parser::yypgoto_[] =
  {
     -46,   -46,   -46,   -46,   -46,   -46,   185,   -46,   -46,   168,
     -46,   136,   -12,   123,   -46,   -45,    14,   -46,    -5
  };

  const unsigned char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     9,     4,   142,    10,    21,    28,    29,
      45,    56,    57,    23,    64,    58,    87,   156,    88
  };

  const unsigned char
  parser::yytable_[] =
  {
      12,   104,    43,    13,     1,    22,     5,    65,     7,    30,
      11,    72,    24,   102,   103,   104,    24,     6,    31,    79,
      16,    14,    24,    18,   108,   109,    93,    73,     8,    39,
      72,    44,    19,    49,   111,   112,   102,   103,   104,    24,
      19,     8,    59,    60,    71,    24,    63,    66,   111,   112,
      20,    59,   120,    27,    17,    74,    59,    76,    20,    66,
     127,    11,    50,    71,   100,   159,    66,    25,   136,    11,
      59,   111,   112,   111,   112,   143,    35,    26,   102,   103,
     104,   101,    89,    91,    92,    27,    32,    94,    95,   108,
     109,   110,    66,    11,   160,    98,    99,   152,   133,    11,
      66,   154,    33,    37,    38,    40,   134,    41,    66,    19,
     119,    42,    52,   111,   112,    66,   124,   125,   126,    46,
     128,   129,   130,   131,   132,    47,   135,    20,    53,    51,
      54,    55,    70,   102,   103,   104,   144,    66,    11,    67,
      61,    66,   106,   107,   108,   109,   110,   102,   103,   104,
      34,    77,    68,    69,   149,   114,   106,   107,   108,   109,
     110,   155,    97,   122,   123,   137,   139,    48,   111,   112,
     118,   138,   140,    62,   161,   145,   102,   103,   104,   147,
     146,   150,   111,   112,   148,   106,   107,   108,   109,   110,
     102,   103,   104,   158,    15,   105,    36,    75,     0,   106,
     107,   108,   109,   110,     0,   102,   103,   104,     0,     0,
     113,   111,   112,   153,   106,   107,   108,   109,   110,   102,
     103,   104,     0,     0,   115,   111,   112,     0,   106,   107,
     108,   109,   110,   102,   103,   104,     0,     0,     0,     0,
     111,   112,   106,   107,   108,   109,   110,   102,   103,   104,
       0,     0,     0,     0,   111,   112,   106,   107,   108,   109,
     110,     0,   102,   103,   104,     0,   116,   121,   111,   112,
       0,   106,   107,   108,   109,   110,   102,   103,   104,     0,
     117,     0,   111,   112,     0,   106,   107,   108,   109,   110,
     102,   103,   104,     0,     0,     0,     0,   111,   112,   106,
     107,   108,   109,   110,   102,   103,   104,     0,     0,   141,
       0,   111,   112,   106,   107,   108,   109,   110,   102,   103,
     104,     0,     0,   157,     0,   111,   112,   106,    90,   108,
     109,   110,     0,    80,    81,     0,     0,     0,     0,   111,
     112,    80,    81,     0,    82,     0,     0,     0,     0,     0,
       0,     0,    82,   111,   112,     0,     0,    83,    84,    85,
      86,    19,    11,     0,    52,    83,    84,    85,    86,     0,
      11,     0,     0,    19,     0,     0,    52,     0,     0,    20,
      53,     0,    54,    55,    96,    52,    78,     0,     0,     0,
      11,    20,    53,     0,    54,    55,    52,   151,     0,     0,
      52,    53,    11,    54,    55,     0,     0,     0,     0,     0,
       0,    11,    53,     0,    54,    55,    53,     0,    54,    55,
       0,     0,    11,     0,     0,     0,    11
  };

  const short
  parser::yycheck_[] =
  {
       5,     5,     8,     8,    19,    17,    20,    52,     0,    21,
      35,    56,    17,     3,     4,     5,    21,     0,    23,    64,
       9,     0,    27,    19,    14,    15,    71,    11,    20,    34,
      75,    37,     6,     8,    38,    39,     3,     4,     5,    44,
       6,    20,    47,    48,    56,    50,    51,    52,    38,    39,
      24,    56,    97,    19,     9,    39,    61,    62,    24,    64,
     105,    35,    37,    75,     6,     8,    71,    18,   113,    35,
      75,    38,    39,    38,    39,   120,    10,    39,     3,     4,
       5,    86,    68,    69,    70,    19,    21,    73,    74,    14,
      15,    16,    97,    35,    37,    81,    82,   142,    34,    35,
     105,   146,    40,    36,    22,     7,   111,     7,   113,     6,
      96,    23,     9,    38,    39,   120,   102,   103,   104,    39,
     106,   107,   108,   109,   110,     9,   112,    24,    25,    40,
      27,    28,    29,     3,     4,     5,   122,   142,    35,     7,
       9,   146,    12,    13,    14,    15,    16,     3,     4,     5,
      27,     8,     7,     7,   140,     8,    12,    13,    14,    15,
      16,   147,     9,    39,     7,    36,    10,    44,    38,    39,
      40,    36,    11,    50,   160,     8,     3,     4,     5,     7,
      26,    10,    38,    39,    40,    12,    13,    14,    15,    16,
       3,     4,     5,    10,     9,     8,    28,    61,    -1,    12,
      13,    14,    15,    16,    -1,     3,     4,     5,    -1,    -1,
       8,    38,    39,    40,    12,    13,    14,    15,    16,     3,
       4,     5,    -1,    -1,     8,    38,    39,    -1,    12,    13,
      14,    15,    16,     3,     4,     5,    -1,    -1,    -1,    -1,
      38,    39,    12,    13,    14,    15,    16,     3,     4,     5,
      -1,    -1,    -1,    -1,    38,    39,    12,    13,    14,    15,
      16,    -1,     3,     4,     5,    -1,    36,     8,    38,    39,
      -1,    12,    13,    14,    15,    16,     3,     4,     5,    -1,
      36,    -1,    38,    39,    -1,    12,    13,    14,    15,    16,
       3,     4,     5,    -1,    -1,    -1,    -1,    38,    39,    12,
      13,    14,    15,    16,     3,     4,     5,    -1,    -1,    36,
      -1,    38,    39,    12,    13,    14,    15,    16,     3,     4,
       5,    -1,    -1,    36,    -1,    38,    39,    12,     1,    14,
      15,    16,    -1,     6,     7,    -1,    -1,    -1,    -1,    38,
      39,     6,     7,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    38,    39,    -1,    -1,    30,    31,    32,
      33,     6,    35,    -1,     9,    30,    31,    32,    33,    -1,
      35,    -1,    -1,     6,    -1,    -1,     9,    -1,    -1,    24,
      25,    -1,    27,    28,    29,     9,    10,    -1,    -1,    -1,
      35,    24,    25,    -1,    27,    28,     9,    10,    -1,    -1,
       9,    25,    35,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    25,    -1,    27,    28,    25,    -1,    27,    28,
      -1,    -1,    35,    -1,    -1,    -1,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,    19,    42,    43,    45,    20,     0,     0,    20,    44,
      47,    35,    59,    59,     0,    47,     9,     9,    19,     6,
      24,    48,    53,    54,    59,    18,    39,    19,    49,    50,
      53,    59,    21,    40,    54,    10,    50,    36,    22,    59,
       7,     7,    23,     8,    37,    51,    39,     9,    54,     8,
      37,    40,     9,    25,    27,    28,    52,    53,    56,    59,
      59,     9,    54,    59,    55,    56,    59,     7,     7,     7,
      29,    53,    56,    11,    39,    52,    59,     8,    10,    56,
       6,     7,    17,    30,    31,    32,    33,    57,    59,    57,
       1,    57,    57,    56,    57,    57,    29,     9,    57,    57,
       6,    59,     3,     4,     5,     8,    12,    13,    14,    15,
      16,    38,    39,     8,     8,     8,    36,    36,    40,    57,
      56,     8,    39,     7,    57,    57,    57,    56,    57,    57,
      57,    57,    57,    34,    59,    57,    56,    36,    36,    10,
      11,    36,    46,    56,    57,     8,    26,     7,    40,    57,
      10,    10,    56,    40,    56,    57,    58,    36,    10,     8,
      37,    57
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    43,    44,    44,    45,    46,    46,
      46,    47,    48,    48,    48,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58,    58,    59
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     3,     1,     2,    19,     0,     1,
       2,     6,     0,     1,     2,     0,     1,     2,    12,    11,
       3,     4,     0,     1,     1,     2,     2,     3,     3,     3,
       1,     1,     1,     0,     1,     2,     3,     7,     5,     5,
       5,     4,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     6,     1,     1,     1,     1,     1,     5,
       4,     2,     3,     0,     1,     3,     1
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
  "ExpressionParams", "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    54,    54,    59,    62,    68,    72,    78,    90,    91,
      95,   102,   111,   112,   116,   122,   123,   127,   133,   142,
     151,   156,   163,   164,   168,   172,   176,   180,   186,   194,
     195,   196,   197,   202,   203,   207,   214,   218,   224,   229,
     233,   238,   243,   250,   255,   260,   265,   270,   275,   280,
     285,   291,   297,   301,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   322,   324,   328,   336
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
#line 1990 "parser.tab.cc"

#line 340 "parser.yy"
