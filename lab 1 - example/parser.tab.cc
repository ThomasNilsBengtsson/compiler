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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
      case symbol_kind::S_MainClass: // MainClass
      case symbol_kind::S_ClassDeclaration: // ClassDeclaration
      case symbol_kind::S_MethodDeclaration: // MethodDeclaration
      case symbol_kind::S_VarDeclaration: // VarDeclaration
      case symbol_kind::S_Type: // Type
      case symbol_kind::S_Statement: // Statement
      case symbol_kind::S_expression: // expression
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
                {root = yystack_[0].value.as < Node * > ();}
#line 783 "parser.tab.cc"
    break;

  case 3: // Goal: MainClass ClassDeclaration
#line 44 "parser.yy"
                                 { 
                yylhs.value.as < Node * > () = new Node("Goal", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
                if(yystack_[0].value.as < Node * > ())
                {
if (yystack_[0].value.as < Node * > ()) {
    for (auto i = std::begin(*yystack_[0].value.as < Node * > ()); i != std::end(*yystack_[0].value.as < Node * > ()); ++i) {
        yylhs.value.as < Node * > ()->children.push_back(*i);
    }
    delete yystack_[0].value.as < Node * > ();  // Free memory after copying elements
}
  
                }
          }
#line 802 "parser.tab.cc"
    break;

  case 4: // MainClass: PUBLIC CLASS Identifier LBRACE PUBLIC STATIC VOID MAIN LP STRING LBRACKET RBRACKET Identifier RP LBRACE Statement Statement RBRACE RBRACE
#line 60 "parser.yy"
                                                                                                                                                     { 
                yylhs.value.as < Node * > () = new Node("MainClass", "", yylineno);
               /*  $$->children.push_back(new Node("Identifier", $3, yylineno));   vet inte ska man ha detta*/
               yylhs.value.as < Node * > ()->children.push_back(yystack_[16].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                if(yystack_[2].value.as < Node * > ())
                {
                  for (auto i : *yystack_[2].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[2].value.as < Node * > ();
                }
          }
#line 822 "parser.tab.cc"
    break;

  case 5: // ClassDeclaration: CLASS Identifier LBRACE VarDeclaration MethodDeclaration RBRACE
#line 79 "parser.yy"
                                                                                  { 
                yylhs.value.as < Node * > () = new Node("ClassDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                if(yystack_[2].value.as < Node * > ())
                {
                  for (auto i : *yystack_[2].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[2].value.as < Node * > ();
                }
                if(yystack_[1].value.as < Node * > ())
                {
                  for (auto i : *yystack_[1].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[1].value.as < Node * > ();
                }
          }
#line 847 "parser.tab.cc"
    break;

  case 6: // MethodDeclaration: PUBLIC Type Identifier LP Type Identifier COMMA Type Identifier RP LBRACE VarDeclaration Statement RETURN expression SEMICOLON RBRACE
#line 102 "parser.yy"
                                                                                                                                                         { 
                yylhs.value.as < Node * > () = new Node("MethodDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[15].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[14].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[11].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[9].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[8].value.as < Node * > ());
                if(yystack_[9].value.as < Node * > () && yystack_[8].value.as < Node * > ())
                {
                  for (auto i : *yystack_[9].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[9].value.as < Node * > ();

                  for (auto i : *yystack_[8].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                }
                /* måste lägga till för flera parameterar för 8 och 9 */
                if(yystack_[5].value.as < Node * > ())
                {
                  for (auto i : *yystack_[5].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[5].value.as < Node * > ();
                }
                if(yystack_[4].value.as < Node * > ())
                {
                  for (auto i : *yystack_[4].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[4].value.as < Node * > ();
                }
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < std::string > ());
          }
#line 891 "parser.tab.cc"
    break;

  case 7: // VarDeclaration: Type Identifier SEMICOLON
#line 144 "parser.yy"
                                          { 
                yylhs.value.as < Node * > () = new Node("VarDeclaration", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 901 "parser.tab.cc"
    break;

  case 8: // Type: INT LBRACKET RBRACKET
#line 152 "parser.yy"
                            { yylhs.value.as < Node * > () = new Node("IntArray", "", yylineno); }
#line 907 "parser.tab.cc"
    break;

  case 9: // Type: BOOLEAN
#line 153 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("Boolean", "", yylineno); }
#line 913 "parser.tab.cc"
    break;

  case 10: // Type: INT
#line 154 "parser.yy"
          { yylhs.value.as < Node * > () = new Node("Int", "", yylineno); }
#line 919 "parser.tab.cc"
    break;

  case 11: // Type: IDENTIFIER
#line 155 "parser.yy"
                 { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); }
#line 925 "parser.tab.cc"
    break;

  case 12: // Statement: LBRACE Statement RBRACE
#line 158 "parser.yy"
                                   {
                yylhs.value.as < Node * > () = new Node("Block", "", yylineno);
                if(yystack_[1].value.as < Node * > ())
                {
                  for (auto i : *yystack_[1].value.as < Node * > ())
                  {
                    yylhs.value.as < Node * > ()->children.push_back(i);
                  }
                  delete yystack_[1].value.as < Node * > ();
                }
          }
#line 941 "parser.tab.cc"
    break;

  case 13: // Statement: IF LP expression RP Statement ELSE Statement
#line 169 "parser.yy"
                                                       { 
                yylhs.value.as < Node * > () = new Node("IfStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 952 "parser.tab.cc"
    break;

  case 14: // Statement: WHILE LP expression RP Statement
#line 175 "parser.yy"
                                           { 
                yylhs.value.as < Node * > () = new Node("WhileStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 962 "parser.tab.cc"
    break;

  case 15: // Statement: SYSTEM_OUT_PRINTLN LP expression RP SEMICOLON
#line 180 "parser.yy"
                                                        { 
                yylhs.value.as < Node * > () = new Node("PrintStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
          }
#line 971 "parser.tab.cc"
    break;

  case 16: // Statement: Identifier ASSIGN expression SEMICOLON
#line 184 "parser.yy"
                                                 { 
                yylhs.value.as < Node * > () = new Node("AssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 981 "parser.tab.cc"
    break;

  case 17: // Statement: Identifier LBRACKET expression RBRACKET ASSIGN expression SEMICOLON
#line 189 "parser.yy"
                                                                              { 
                yylhs.value.as < Node * > () = new Node("ArrayAssignStatement", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[6].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[4].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 992 "parser.tab.cc"
    break;

  case 18: // expression: expression PLUSOP expression
#line 196 "parser.yy"
                                         { 
                yylhs.value.as < Node * > () = new Node("AddExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1002 "parser.tab.cc"
    break;

  case 19: // expression: expression MINUSOP expression
#line 201 "parser.yy"
                                        { 
                yylhs.value.as < Node * > () = new Node("SubExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1012 "parser.tab.cc"
    break;

  case 20: // expression: expression MULTOP expression
#line 206 "parser.yy"
                                       { 
                yylhs.value.as < Node * > () = new Node("MultExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1022 "parser.tab.cc"
    break;

  case 21: // expression: expression AND expression
#line 211 "parser.yy"
                                    { 
                yylhs.value.as < Node * > () = new Node("AndExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1032 "parser.tab.cc"
    break;

  case 22: // expression: expression OR expression
#line 216 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("OrExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1042 "parser.tab.cc"
    break;

  case 23: // expression: expression LT expression
#line 221 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("LtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1052 "parser.tab.cc"
    break;

  case 24: // expression: expression GT expression
#line 226 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("GtExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1062 "parser.tab.cc"
    break;

  case 25: // expression: expression EQ expression
#line 231 "parser.yy"
                                   { 
                yylhs.value.as < Node * > () = new Node("EqExpression", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[2].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ());
          }
#line 1072 "parser.tab.cc"
    break;

  case 26: // expression: expression LBRACKET expression RBRACKET
#line 252 "parser.yy"
                                                  {
                yylhs.value.as < Node * > () = new Node("ArrayAccess", "", yylineno);
                yylhs.value.as < Node * > ()->children.push_back(yystack_[3].value.as < Node * > ());
                yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ());
          }
#line 1082 "parser.tab.cc"
    break;

  case 27: // expression: INT
#line 270 "parser.yy"
              { yylhs.value.as < Node * > () = new Node("IntLiteral", yystack_[0].value.as < std::string > (), yylineno); }
#line 1088 "parser.tab.cc"
    break;

  case 28: // expression: TRUE
#line 271 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "true", yylineno); }
#line 1094 "parser.tab.cc"
    break;

  case 29: // expression: FALSE
#line 272 "parser.yy"
                { yylhs.value.as < Node * > () = new Node("BooleanLiteral", "false", yylineno); }
#line 1100 "parser.tab.cc"
    break;

  case 30: // expression: Identifier
#line 273 "parser.yy"
                     { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1106 "parser.tab.cc"
    break;

  case 31: // expression: THIS
#line 274 "parser.yy"
               { yylhs.value.as < Node * > () = new Node("This", "", yylineno); }
#line 1112 "parser.tab.cc"
    break;

  case 32: // expression: NEW INT LBRACKET expression RBRACKET
#line 275 "parser.yy"
                                               { yylhs.value.as < Node * > () = new Node("NewArrayExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[1].value.as < Node * > ()); }
#line 1118 "parser.tab.cc"
    break;

  case 33: // expression: NOT expression
#line 277 "parser.yy"
                         { yylhs.value.as < Node * > () = new Node("NotExpression", "", yylineno); yylhs.value.as < Node * > ()->children.push_back(yystack_[0].value.as < Node * > ()); }
#line 1124 "parser.tab.cc"
    break;

  case 34: // expression: factor
#line 279 "parser.yy"
                 { yylhs.value.as < Node * > () = yystack_[0].value.as < Node * > (); }
#line 1130 "parser.tab.cc"
    break;

  case 35: // factor: INT
#line 285 "parser.yy"
                          {  yylhs.value.as < Node * > () = new Node("Int", yystack_[0].value.as < std::string > (), yylineno); /* printf("r5 ");  Here we create a leaf node Int. The value of the leaf node is $1 */}
#line 1136 "parser.tab.cc"
    break;

  case 36: // factor: LP expression RP
#line 286 "parser.yy"
                               { yylhs.value.as < Node * > () = yystack_[1].value.as < Node * > (); /* printf("r6 ");  simply return the expression */}
#line 1142 "parser.tab.cc"
    break;

  case 37: // Identifier: IDENTIFIER
#line 291 "parser.yy"
                       { yylhs.value.as < Node * > () = new Node("Identifier", yystack_[0].value.as < std::string > (), yylineno); /* printf("r7 "); */}
#line 1148 "parser.tab.cc"
    break;


#line 1152 "parser.tab.cc"

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


  const signed char parser::yypact_ninf_ = -43;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
     -14,   -13,     6,   -43,   -11,   -25,   -43,   -25,   -43,   -43,
       3,     4,    -8,    -3,     1,   -16,   -43,   -43,    15,   -25,
      14,     0,    -3,    28,     7,    22,   -43,   -25,   -43,   -43,
      39,    40,    25,    -3,    11,   -25,    13,    17,   -25,    -3,
      48,   -25,    50,    54,   236,    55,   236,    56,    61,    63,
     236,   -10,    -3,    59,   224,   224,   224,    70,   224,   224,
     236,   -43,   -43,   224,   224,   -43,   -43,   -43,    65,   123,
     -43,   -43,   137,   151,    71,   165,    12,    44,   179,   212,
      43,   224,   224,   224,   236,   224,   224,   224,   224,   224,
     224,   236,    60,   -43,   -43,    86,   224,   -43,   224,    62,
      62,   221,    73,   212,   212,   212,   212,   212,    90,   -43,
     -43,   224,   193,   107,   236,   -43,   207,    97,   -43,   -43,
     -43,   -43
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     1,     0,     3,    37,
       0,     0,     0,     0,     0,    10,     9,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     5,     7,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    12,    27,     0,     0,    28,    29,    31,     0,     0,
      34,    30,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,    16,     0,     0,    36,     0,    18,
      19,    20,     0,    21,    22,    23,    24,    25,     0,    14,
      15,     0,     0,     0,     0,    26,     0,     0,    32,    13,
      17,     6
  };

  const signed char
  parser::yypgoto_[] =
  {
     -43,   -43,   -43,   -43,   -43,   -43,    64,    -2,   -42,     2,
     -43,    -5
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     8,    23,    18,    19,    50,    69,
      70,    71
  };

  const signed char
  parser::yytable_[] =
  {
      10,    58,    11,    15,    53,     1,     6,     5,    57,     7,
       9,    14,    12,    13,    24,    81,    82,    83,    77,    20,
      27,    16,    31,    21,    85,    86,    87,    88,    89,    59,
      37,    35,    17,    40,    22,    25,    43,    41,    28,    51,
      26,    51,   102,    29,    30,    51,    32,    33,    34,   109,
      36,    90,    95,    38,    39,    51,    42,    72,    73,    44,
      75,    76,    45,    54,    52,    78,    79,    83,    55,    61,
      56,    80,   119,    96,    85,    86,    87,    88,    89,    51,
      74,    93,    98,    99,   100,   101,    51,   103,   104,   105,
     106,   107,   108,    81,    82,    83,   110,   111,   112,   114,
     113,    90,    85,    86,    87,    88,    89,   121,     0,    51,
      81,    82,    83,   116,     0,     0,    60,     0,     0,    85,
      86,    87,    88,    89,     0,     0,    81,    82,    83,    90,
     115,    84,     0,     0,     0,    85,    86,    87,    88,    89,
      81,    82,    83,     0,     0,    91,    90,   118,     0,    85,
      86,    87,    88,    89,    81,    82,    83,     0,     0,    92,
       0,     0,    90,    85,    86,    87,    88,    89,    81,    82,
      83,     0,     0,     0,     0,     0,    90,    85,    86,    87,
      88,    89,    81,    82,    83,     0,     0,    97,     0,     0,
      90,    85,    86,    87,    88,    89,    81,    82,    83,     0,
       0,    94,     0,     0,    90,    85,    86,    87,    88,    89,
      81,    82,    83,     0,     0,    81,    82,    83,    90,    85,
      86,    87,    88,    89,    85,    86,    87,    88,    89,   117,
      62,    63,    90,    85,    86,    87,    88,    89,     0,     0,
       0,    64,     0,   120,     0,    46,    90,     0,     0,     0,
       0,    90,     0,     0,    65,    66,    67,    68,     0,     9,
      90,    47,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     9
  };

  const signed char
  parser::yycheck_[] =
  {
       5,    11,     7,     6,    46,    19,     0,    20,    50,    20,
      35,    19,     9,     9,    19,     3,     4,     5,    60,    18,
      22,    24,    27,    39,    12,    13,    14,    15,    16,    39,
      35,    33,    35,    38,    19,    21,    41,    39,    10,    44,
      40,    46,    84,    36,    22,    50,     7,     7,    23,    91,
      39,    39,    40,    40,    37,    60,     8,    55,    56,     9,
      58,    59,     8,     7,     9,    63,    64,     5,     7,    10,
       7,     6,   114,    29,    12,    13,    14,    15,    16,    84,
      10,    10,    39,    81,    82,    83,    91,    85,    86,    87,
      88,    89,    90,     3,     4,     5,    36,    11,    96,    26,
      98,    39,    12,    13,    14,    15,    16,    10,    -1,   114,
       3,     4,     5,   111,    -1,    -1,    52,    -1,    -1,    12,
      13,    14,    15,    16,    -1,    -1,     3,     4,     5,    39,
      40,     8,    -1,    -1,    -1,    12,    13,    14,    15,    16,
       3,     4,     5,    -1,    -1,     8,    39,    40,    -1,    12,
      13,    14,    15,    16,     3,     4,     5,    -1,    -1,     8,
      -1,    -1,    39,    12,    13,    14,    15,    16,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    39,    12,    13,    14,
      15,    16,     3,     4,     5,    -1,    -1,     8,    -1,    -1,
      39,    12,    13,    14,    15,    16,     3,     4,     5,    -1,
      -1,    36,    -1,    -1,    39,    12,    13,    14,    15,    16,
       3,     4,     5,    -1,    -1,     3,     4,     5,    39,    12,
      13,    14,    15,    16,    12,    13,    14,    15,    16,    36,
       6,     7,    39,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    17,    -1,    36,    -1,     9,    39,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    30,    31,    32,    33,    -1,    35,
      39,    25,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    35
  };

  const signed char
  parser::yystos_[] =
  {
       0,    19,    42,    43,    44,    20,     0,    20,    45,    35,
      52,    52,     9,     9,    19,     6,    24,    35,    47,    48,
      18,    39,    19,    46,    52,    21,    40,    48,    10,    36,
      22,    52,     7,     7,    23,    48,    39,    52,    40,    37,
      52,    48,     8,    52,     9,     8,     9,    25,    27,    28,
      49,    52,     9,    49,     7,     7,     7,    49,    11,    39,
      47,    10,     6,     7,    17,    30,    31,    32,    33,    50,
      51,    52,    50,    50,    10,    50,    50,    49,    50,    50,
       6,     3,     4,     5,     8,    12,    13,    14,    15,    16,
      39,     8,     8,    10,    36,    40,    29,     8,    39,    50,
      50,    50,    49,    50,    50,    50,    50,    50,    50,    49,
      36,    11,    50,    50,    26,    40,    50,    36,    40,    49,
      36,    10
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    43,    44,    45,    46,    47,    48,    48,
      48,    48,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    51,    52
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,    19,     6,    17,     3,     3,     1,
       1,     1,     3,     7,     5,     5,     4,     7,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     1,     1,     1,
       1,     1,     5,     2,     1,     1,     3,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "PLUSOP", "MINUSOP",
  "MULTOP", "INT", "LP", "RP", "LBRACE", "RBRACE", "ASSIGN", "AND", "OR",
  "LT", "GT", "EQ", "NOT", "STATIC", "PUBLIC", "CLASS", "VOID", "MAIN",
  "STRING", "BOOLEAN", "IF", "ELSE", "WHILE", "SYSTEM_OUT_PRINTLN",
  "RETURN", "TRUE", "FALSE", "THIS", "NEW", "LENGTH", "IDENTIFIER",
  "SEMICOLON", "COMMA", "DOT", "LBRACKET", "RBRACKET", "$accept", "root",
  "Goal", "MainClass", "ClassDeclaration", "MethodDeclaration",
  "VarDeclaration", "Type", "Statement", "expression", "factor",
  "Identifier", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,    41,    41,    44,    60,    79,   102,   144,   152,   153,
     154,   155,   158,   169,   175,   180,   184,   189,   196,   201,
     206,   211,   216,   221,   226,   231,   252,   270,   271,   272,
     273,   274,   275,   277,   279,   285,   286,   291
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
#line 1715 "parser.tab.cc"

#line 295 "parser.yy"
