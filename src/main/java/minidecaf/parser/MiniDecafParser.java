package minidecaf.parser;

// Generated from MiniDecafParser.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniDecafParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.7.1", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		IF=1, ELSE=2, WHILE=3, FOR=4, RETURN=5, SIZEOF=6, INT=7, CHAR=8, ADD=9, 
		SUB=10, MUL=11, DIV=12, AND=13, ASSIGN=14, GT=15, LT=16, LE=17, GE=18, 
		EQ=19, NE=20, LPAREN=21, RPAREN=22, LBRACE=23, RBRACE=24, LBRACK=25, RBRACK=26, 
		SEMI=27, COMMA=28, WS=29, COMMENT=30, LINE_COMMENT=31, IDENT=32, NUM=33;
	public static final int
		RULE_program = 0, RULE_func = 1, RULE_stmt = 2, RULE_expr = 3, RULE_relational = 4, 
		RULE_add = 5, RULE_mul = 6, RULE_unary = 7, RULE_primary = 8;
	public static final String[] ruleNames = {
		"program", "func", "stmt", "expr", "relational", "add", "mul", "unary", 
		"primary"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'if'", "'else'", "'while'", "'for'", "'return'", "'sizeof'", "'int'", 
		"'char'", "'+'", "'-'", "'*'", "'/'", "'&'", "'='", "'>'", "'<'", "'<='", 
		"'>='", "'=='", "'!='", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", 
		"','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "IF", "ELSE", "WHILE", "FOR", "RETURN", "SIZEOF", "INT", "CHAR", 
		"ADD", "SUB", "MUL", "DIV", "AND", "ASSIGN", "GT", "LT", "LE", "GE", "EQ", 
		"NE", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", "SEMI", 
		"COMMA", "WS", "COMMENT", "LINE_COMMENT", "IDENT", "NUM"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MiniDecafParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MiniDecafParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class ProgramContext extends ParserRuleContext {
		public List<FuncContext> func() {
			return getRuleContexts(FuncContext.class);
		}
		public FuncContext func(int i) {
			return getRuleContext(FuncContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitProgram(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(21);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==IDENT) {
				{
				{
				setState(18);
				func();
				}
				}
				setState(23);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FuncContext extends ParserRuleContext {
		public List<TerminalNode> IDENT() { return getTokens(MiniDecafParser.IDENT); }
		public TerminalNode IDENT(int i) {
			return getToken(MiniDecafParser.IDENT, i);
		}
		public TerminalNode LPAREN() { return getToken(MiniDecafParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(MiniDecafParser.RPAREN, 0); }
		public TerminalNode LBRACE() { return getToken(MiniDecafParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(MiniDecafParser.RBRACE, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(MiniDecafParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MiniDecafParser.COMMA, i);
		}
		public FuncContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_func; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitFunc(this);
			else return visitor.visitChildren(this);
		}
	}

	public final FuncContext func() throws RecognitionException {
		FuncContext _localctx = new FuncContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_func);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(24);
			match(IDENT);
			setState(25);
			match(LPAREN);
			setState(34);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==IDENT) {
				{
				setState(26);
				match(IDENT);
				setState(31);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==COMMA) {
					{
					{
					setState(27);
					match(COMMA);
					setState(28);
					match(IDENT);
					}
					}
					setState(33);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				}
			}

			setState(36);
			match(RPAREN);
			setState(37);
			match(LBRACE);
			setState(41);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << WHILE) | (1L << FOR) | (1L << RETURN) | (1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << LBRACE) | (1L << IDENT) | (1L << NUM))) != 0)) {
				{
				{
				setState(38);
				stmt();
				}
				}
				setState(43);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(44);
			match(RBRACE);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	 
		public StmtContext() { }
		public void copyFrom(StmtContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ExprStmtContext extends StmtContext {
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(MiniDecafParser.SEMI, 0); }
		public ExprStmtContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitExprStmt(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ForStmtContext extends StmtContext {
		public TerminalNode FOR() { return getToken(MiniDecafParser.FOR, 0); }
		public TerminalNode LPAREN() { return getToken(MiniDecafParser.LPAREN, 0); }
		public List<TerminalNode> SEMI() { return getTokens(MiniDecafParser.SEMI); }
		public TerminalNode SEMI(int i) {
			return getToken(MiniDecafParser.SEMI, i);
		}
		public TerminalNode RPAREN() { return getToken(MiniDecafParser.RPAREN, 0); }
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public ForStmtContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitForStmt(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class WhileStmtContext extends StmtContext {
		public TerminalNode WHILE() { return getToken(MiniDecafParser.WHILE, 0); }
		public TerminalNode LPAREN() { return getToken(MiniDecafParser.LPAREN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(MiniDecafParser.RPAREN, 0); }
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public WhileStmtContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitWhileStmt(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class IfStmtContext extends StmtContext {
		public TerminalNode IF() { return getToken(MiniDecafParser.IF, 0); }
		public TerminalNode LPAREN() { return getToken(MiniDecafParser.LPAREN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(MiniDecafParser.RPAREN, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public TerminalNode ELSE() { return getToken(MiniDecafParser.ELSE, 0); }
		public IfStmtContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitIfStmt(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class BlockStmtContext extends StmtContext {
		public TerminalNode LBRACE() { return getToken(MiniDecafParser.LBRACE, 0); }
		public TerminalNode RBRACE() { return getToken(MiniDecafParser.RBRACE, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public BlockStmtContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitBlockStmt(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ReturnStmtContext extends StmtContext {
		public TerminalNode RETURN() { return getToken(MiniDecafParser.RETURN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode SEMI() { return getToken(MiniDecafParser.SEMI, 0); }
		public ReturnStmtContext(StmtContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitReturnStmt(this);
			else return visitor.visitChildren(this);
		}
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_stmt);
		int _la;
		try {
			setState(91);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case ADD:
			case SUB:
			case LPAREN:
			case IDENT:
			case NUM:
				_localctx = new ExprStmtContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(46);
				expr();
				setState(47);
				match(SEMI);
				}
				break;
			case RETURN:
				_localctx = new ReturnStmtContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(49);
				match(RETURN);
				setState(50);
				expr();
				setState(51);
				match(SEMI);
				}
				break;
			case LBRACE:
				_localctx = new BlockStmtContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(53);
				match(LBRACE);
				setState(57);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << IF) | (1L << WHILE) | (1L << FOR) | (1L << RETURN) | (1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << LBRACE) | (1L << IDENT) | (1L << NUM))) != 0)) {
					{
					{
					setState(54);
					stmt();
					}
					}
					setState(59);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(60);
				match(RBRACE);
				}
				break;
			case IF:
				_localctx = new IfStmtContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(61);
				match(IF);
				setState(62);
				match(LPAREN);
				setState(63);
				expr();
				setState(64);
				match(RPAREN);
				setState(65);
				stmt();
				setState(68);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,5,_ctx) ) {
				case 1:
					{
					setState(66);
					match(ELSE);
					setState(67);
					stmt();
					}
					break;
				}
				}
				break;
			case WHILE:
				_localctx = new WhileStmtContext(_localctx);
				enterOuterAlt(_localctx, 5);
				{
				setState(70);
				match(WHILE);
				setState(71);
				match(LPAREN);
				setState(72);
				expr();
				setState(73);
				match(RPAREN);
				setState(74);
				stmt();
				}
				break;
			case FOR:
				_localctx = new ForStmtContext(_localctx);
				enterOuterAlt(_localctx, 6);
				{
				setState(76);
				match(FOR);
				setState(77);
				match(LPAREN);
				setState(79);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << IDENT) | (1L << NUM))) != 0)) {
					{
					setState(78);
					expr();
					}
				}

				setState(81);
				match(SEMI);
				setState(83);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << IDENT) | (1L << NUM))) != 0)) {
					{
					setState(82);
					expr();
					}
				}

				setState(85);
				match(SEMI);
				setState(87);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << IDENT) | (1L << NUM))) != 0)) {
					{
					setState(86);
					expr();
					}
				}

				setState(89);
				match(RPAREN);
				setState(90);
				stmt();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprContext extends ParserRuleContext {
		public RelationalContext relational() {
			return getRuleContext(RelationalContext.class,0);
		}
		public TerminalNode ASSIGN() { return getToken(MiniDecafParser.ASSIGN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public ExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expr; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitExpr(this);
			else return visitor.visitChildren(this);
		}
	}

	public final ExprContext expr() throws RecognitionException {
		ExprContext _localctx = new ExprContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(93);
			relational();
			setState(96);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(94);
				match(ASSIGN);
				setState(95);
				expr();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RelationalContext extends ParserRuleContext {
		public List<AddContext> add() {
			return getRuleContexts(AddContext.class);
		}
		public AddContext add(int i) {
			return getRuleContext(AddContext.class,i);
		}
		public TerminalNode EQ() { return getToken(MiniDecafParser.EQ, 0); }
		public TerminalNode NE() { return getToken(MiniDecafParser.NE, 0); }
		public TerminalNode LT() { return getToken(MiniDecafParser.LT, 0); }
		public TerminalNode LE() { return getToken(MiniDecafParser.LE, 0); }
		public TerminalNode GT() { return getToken(MiniDecafParser.GT, 0); }
		public TerminalNode GE() { return getToken(MiniDecafParser.GE, 0); }
		public RelationalContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relational; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitRelational(this);
			else return visitor.visitChildren(this);
		}
	}

	public final RelationalContext relational() throws RecognitionException {
		RelationalContext _localctx = new RelationalContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_relational);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(98);
			add();
			setState(111);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EQ:
				{
				setState(99);
				match(EQ);
				setState(100);
				add();
				}
				break;
			case NE:
				{
				setState(101);
				match(NE);
				setState(102);
				add();
				}
				break;
			case LT:
				{
				setState(103);
				match(LT);
				setState(104);
				add();
				}
				break;
			case LE:
				{
				setState(105);
				match(LE);
				setState(106);
				add();
				}
				break;
			case GT:
				{
				setState(107);
				match(GT);
				setState(108);
				add();
				}
				break;
			case GE:
				{
				setState(109);
				match(GE);
				setState(110);
				add();
				}
				break;
			case ASSIGN:
			case RPAREN:
			case SEMI:
			case COMMA:
				break;
			default:
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AddContext extends ParserRuleContext {
		public List<MulContext> mul() {
			return getRuleContexts(MulContext.class);
		}
		public MulContext mul(int i) {
			return getRuleContext(MulContext.class,i);
		}
		public List<TerminalNode> ADD() { return getTokens(MiniDecafParser.ADD); }
		public TerminalNode ADD(int i) {
			return getToken(MiniDecafParser.ADD, i);
		}
		public List<TerminalNode> SUB() { return getTokens(MiniDecafParser.SUB); }
		public TerminalNode SUB(int i) {
			return getToken(MiniDecafParser.SUB, i);
		}
		public AddContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_add; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitAdd(this);
			else return visitor.visitChildren(this);
		}
	}

	public final AddContext add() throws RecognitionException {
		AddContext _localctx = new AddContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_add);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(113);
			mul();
			setState(120);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ADD || _la==SUB) {
				{
				setState(118);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case ADD:
					{
					setState(114);
					match(ADD);
					setState(115);
					mul();
					}
					break;
				case SUB:
					{
					setState(116);
					match(SUB);
					setState(117);
					mul();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(122);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class MulContext extends ParserRuleContext {
		public List<UnaryContext> unary() {
			return getRuleContexts(UnaryContext.class);
		}
		public UnaryContext unary(int i) {
			return getRuleContext(UnaryContext.class,i);
		}
		public List<TerminalNode> MUL() { return getTokens(MiniDecafParser.MUL); }
		public TerminalNode MUL(int i) {
			return getToken(MiniDecafParser.MUL, i);
		}
		public List<TerminalNode> DIV() { return getTokens(MiniDecafParser.DIV); }
		public TerminalNode DIV(int i) {
			return getToken(MiniDecafParser.DIV, i);
		}
		public MulContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_mul; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitMul(this);
			else return visitor.visitChildren(this);
		}
	}

	public final MulContext mul() throws RecognitionException {
		MulContext _localctx = new MulContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_mul);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(123);
			unary();
			setState(130);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==MUL || _la==DIV) {
				{
				setState(128);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case MUL:
					{
					setState(124);
					match(MUL);
					setState(125);
					unary();
					}
					break;
				case DIV:
					{
					setState(126);
					match(DIV);
					setState(127);
					unary();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(132);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnaryContext extends ParserRuleContext {
		public PrimaryContext primary() {
			return getRuleContext(PrimaryContext.class,0);
		}
		public TerminalNode ADD() { return getToken(MiniDecafParser.ADD, 0); }
		public TerminalNode SUB() { return getToken(MiniDecafParser.SUB, 0); }
		public UnaryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unary; }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitUnary(this);
			else return visitor.visitChildren(this);
		}
	}

	public final UnaryContext unary() throws RecognitionException {
		UnaryContext _localctx = new UnaryContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_unary);
		int _la;
		try {
			setState(141);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,18,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(134);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ADD) {
					{
					setState(133);
					match(ADD);
					}
				}

				setState(136);
				primary();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(138);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==SUB) {
					{
					setState(137);
					match(SUB);
					}
				}

				setState(140);
				primary();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PrimaryContext extends ParserRuleContext {
		public PrimaryContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primary; }
	 
		public PrimaryContext() { }
		public void copyFrom(PrimaryContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class IdentPrimaryContext extends PrimaryContext {
		public TerminalNode IDENT() { return getToken(MiniDecafParser.IDENT, 0); }
		public IdentPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitIdentPrimary(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class ParenthesizePrimaryContext extends PrimaryContext {
		public TerminalNode LPAREN() { return getToken(MiniDecafParser.LPAREN, 0); }
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
		}
		public TerminalNode RPAREN() { return getToken(MiniDecafParser.RPAREN, 0); }
		public ParenthesizePrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitParenthesizePrimary(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class NumPrimaryContext extends PrimaryContext {
		public TerminalNode NUM() { return getToken(MiniDecafParser.NUM, 0); }
		public NumPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitNumPrimary(this);
			else return visitor.visitChildren(this);
		}
	}
	public static class CallPrimaryContext extends PrimaryContext {
		public TerminalNode IDENT() { return getToken(MiniDecafParser.IDENT, 0); }
		public TerminalNode LPAREN() { return getToken(MiniDecafParser.LPAREN, 0); }
		public TerminalNode RPAREN() { return getToken(MiniDecafParser.RPAREN, 0); }
		public List<ExprContext> expr() {
			return getRuleContexts(ExprContext.class);
		}
		public ExprContext expr(int i) {
			return getRuleContext(ExprContext.class,i);
		}
		public List<TerminalNode> COMMA() { return getTokens(MiniDecafParser.COMMA); }
		public TerminalNode COMMA(int i) {
			return getToken(MiniDecafParser.COMMA, i);
		}
		public CallPrimaryContext(PrimaryContext ctx) { copyFrom(ctx); }
		@Override
		public <T> T accept(ParseTreeVisitor<? extends T> visitor) {
			if ( visitor instanceof MiniDecafParserVisitor ) return ((MiniDecafParserVisitor<? extends T>)visitor).visitCallPrimary(this);
			else return visitor.visitChildren(this);
		}
	}

	public final PrimaryContext primary() throws RecognitionException {
		PrimaryContext _localctx = new PrimaryContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_primary);
		int _la;
		try {
			setState(164);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
			case 1:
				_localctx = new NumPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(143);
				match(NUM);
				}
				break;
			case 2:
				_localctx = new IdentPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(144);
				match(IDENT);
				}
				break;
			case 3:
				_localctx = new ParenthesizePrimaryContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(145);
				match(LPAREN);
				setState(146);
				expr();
				setState(147);
				match(RPAREN);
				}
				break;
			case 4:
				_localctx = new CallPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 4);
				{
				setState(149);
				match(IDENT);
				setState(162);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==LPAREN) {
					{
					setState(150);
					match(LPAREN);
					setState(159);
					_errHandler.sync(this);
					_la = _input.LA(1);
					if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << IDENT) | (1L << NUM))) != 0)) {
						{
						setState(151);
						expr();
						setState(156);
						_errHandler.sync(this);
						_la = _input.LA(1);
						while (_la==COMMA) {
							{
							{
							setState(152);
							match(COMMA);
							setState(153);
							expr();
							}
							}
							setState(158);
							_errHandler.sync(this);
							_la = _input.LA(1);
						}
						}
					}

					setState(161);
					match(RPAREN);
					}
				}

				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3#\u00a9\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\3\2\7\2"+
		"\26\n\2\f\2\16\2\31\13\2\3\3\3\3\3\3\3\3\3\3\7\3 \n\3\f\3\16\3#\13\3\5"+
		"\3%\n\3\3\3\3\3\3\3\7\3*\n\3\f\3\16\3-\13\3\3\3\3\3\3\4\3\4\3\4\3\4\3"+
		"\4\3\4\3\4\3\4\3\4\7\4:\n\4\f\4\16\4=\13\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4"+
		"\3\4\5\4G\n\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\5\4R\n\4\3\4\3\4\5\4"+
		"V\n\4\3\4\3\4\5\4Z\n\4\3\4\3\4\5\4^\n\4\3\5\3\5\3\5\5\5c\n\5\3\6\3\6\3"+
		"\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6r\n\6\3\7\3\7\3\7\3\7\3"+
		"\7\7\7y\n\7\f\7\16\7|\13\7\3\b\3\b\3\b\3\b\3\b\7\b\u0083\n\b\f\b\16\b"+
		"\u0086\13\b\3\t\5\t\u0089\n\t\3\t\3\t\5\t\u008d\n\t\3\t\5\t\u0090\n\t"+
		"\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\3\n\7\n\u009d\n\n\f\n\16\n\u00a0"+
		"\13\n\5\n\u00a2\n\n\3\n\5\n\u00a5\n\n\5\n\u00a7\n\n\3\n\2\2\13\2\4\6\b"+
		"\n\f\16\20\22\2\2\2\u00c1\2\27\3\2\2\2\4\32\3\2\2\2\6]\3\2\2\2\b_\3\2"+
		"\2\2\nd\3\2\2\2\fs\3\2\2\2\16}\3\2\2\2\20\u008f\3\2\2\2\22\u00a6\3\2\2"+
		"\2\24\26\5\4\3\2\25\24\3\2\2\2\26\31\3\2\2\2\27\25\3\2\2\2\27\30\3\2\2"+
		"\2\30\3\3\2\2\2\31\27\3\2\2\2\32\33\7\"\2\2\33$\7\27\2\2\34!\7\"\2\2\35"+
		"\36\7\36\2\2\36 \7\"\2\2\37\35\3\2\2\2 #\3\2\2\2!\37\3\2\2\2!\"\3\2\2"+
		"\2\"%\3\2\2\2#!\3\2\2\2$\34\3\2\2\2$%\3\2\2\2%&\3\2\2\2&\'\7\30\2\2\'"+
		"+\7\31\2\2(*\5\6\4\2)(\3\2\2\2*-\3\2\2\2+)\3\2\2\2+,\3\2\2\2,.\3\2\2\2"+
		"-+\3\2\2\2./\7\32\2\2/\5\3\2\2\2\60\61\5\b\5\2\61\62\7\35\2\2\62^\3\2"+
		"\2\2\63\64\7\7\2\2\64\65\5\b\5\2\65\66\7\35\2\2\66^\3\2\2\2\67;\7\31\2"+
		"\28:\5\6\4\298\3\2\2\2:=\3\2\2\2;9\3\2\2\2;<\3\2\2\2<>\3\2\2\2=;\3\2\2"+
		"\2>^\7\32\2\2?@\7\3\2\2@A\7\27\2\2AB\5\b\5\2BC\7\30\2\2CF\5\6\4\2DE\7"+
		"\4\2\2EG\5\6\4\2FD\3\2\2\2FG\3\2\2\2G^\3\2\2\2HI\7\5\2\2IJ\7\27\2\2JK"+
		"\5\b\5\2KL\7\30\2\2LM\5\6\4\2M^\3\2\2\2NO\7\6\2\2OQ\7\27\2\2PR\5\b\5\2"+
		"QP\3\2\2\2QR\3\2\2\2RS\3\2\2\2SU\7\35\2\2TV\5\b\5\2UT\3\2\2\2UV\3\2\2"+
		"\2VW\3\2\2\2WY\7\35\2\2XZ\5\b\5\2YX\3\2\2\2YZ\3\2\2\2Z[\3\2\2\2[\\\7\30"+
		"\2\2\\^\5\6\4\2]\60\3\2\2\2]\63\3\2\2\2]\67\3\2\2\2]?\3\2\2\2]H\3\2\2"+
		"\2]N\3\2\2\2^\7\3\2\2\2_b\5\n\6\2`a\7\20\2\2ac\5\b\5\2b`\3\2\2\2bc\3\2"+
		"\2\2c\t\3\2\2\2dq\5\f\7\2ef\7\25\2\2fr\5\f\7\2gh\7\26\2\2hr\5\f\7\2ij"+
		"\7\22\2\2jr\5\f\7\2kl\7\23\2\2lr\5\f\7\2mn\7\21\2\2nr\5\f\7\2op\7\24\2"+
		"\2pr\5\f\7\2qe\3\2\2\2qg\3\2\2\2qi\3\2\2\2qk\3\2\2\2qm\3\2\2\2qo\3\2\2"+
		"\2qr\3\2\2\2r\13\3\2\2\2sz\5\16\b\2tu\7\13\2\2uy\5\16\b\2vw\7\f\2\2wy"+
		"\5\16\b\2xt\3\2\2\2xv\3\2\2\2y|\3\2\2\2zx\3\2\2\2z{\3\2\2\2{\r\3\2\2\2"+
		"|z\3\2\2\2}\u0084\5\20\t\2~\177\7\r\2\2\177\u0083\5\20\t\2\u0080\u0081"+
		"\7\16\2\2\u0081\u0083\5\20\t\2\u0082~\3\2\2\2\u0082\u0080\3\2\2\2\u0083"+
		"\u0086\3\2\2\2\u0084\u0082\3\2\2\2\u0084\u0085\3\2\2\2\u0085\17\3\2\2"+
		"\2\u0086\u0084\3\2\2\2\u0087\u0089\7\13\2\2\u0088\u0087\3\2\2\2\u0088"+
		"\u0089\3\2\2\2\u0089\u008a\3\2\2\2\u008a\u0090\5\22\n\2\u008b\u008d\7"+
		"\f\2\2\u008c\u008b\3\2\2\2\u008c\u008d\3\2\2\2\u008d\u008e\3\2\2\2\u008e"+
		"\u0090\5\22\n\2\u008f\u0088\3\2\2\2\u008f\u008c\3\2\2\2\u0090\21\3\2\2"+
		"\2\u0091\u00a7\7#\2\2\u0092\u00a7\7\"\2\2\u0093\u0094\7\27\2\2\u0094\u0095"+
		"\5\b\5\2\u0095\u0096\7\30\2\2\u0096\u00a7\3\2\2\2\u0097\u00a4\7\"\2\2"+
		"\u0098\u00a1\7\27\2\2\u0099\u009e\5\b\5\2\u009a\u009b\7\36\2\2\u009b\u009d"+
		"\5\b\5\2\u009c\u009a\3\2\2\2\u009d\u00a0\3\2\2\2\u009e\u009c\3\2\2\2\u009e"+
		"\u009f\3\2\2\2\u009f\u00a2\3\2\2\2\u00a0\u009e\3\2\2\2\u00a1\u0099\3\2"+
		"\2\2\u00a1\u00a2\3\2\2\2\u00a2\u00a3\3\2\2\2\u00a3\u00a5\7\30\2\2\u00a4"+
		"\u0098\3\2\2\2\u00a4\u00a5\3\2\2\2\u00a5\u00a7\3\2\2\2\u00a6\u0091\3\2"+
		"\2\2\u00a6\u0092\3\2\2\2\u00a6\u0093\3\2\2\2\u00a6\u0097\3\2\2\2\u00a7"+
		"\23\3\2\2\2\31\27!$+;FQUY]bqxz\u0082\u0084\u0088\u008c\u008f\u009e\u00a1"+
		"\u00a4\u00a6";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}