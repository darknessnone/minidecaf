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
		RULE_program = 0, RULE_stmt = 1, RULE_expr = 2, RULE_relational = 3, RULE_add = 4, 
		RULE_mul = 5, RULE_unary = 6, RULE_primary = 7;
	public static final String[] ruleNames = {
		"program", "stmt", "expr", "relational", "add", "mul", "unary", "primary"
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
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
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
			setState(19);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << RETURN) | (1L << ADD) | (1L << SUB) | (1L << LPAREN) | (1L << IDENT) | (1L << NUM))) != 0)) {
				{
				{
				setState(16);
				stmt();
				}
				}
				setState(21);
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
		enterRule(_localctx, 2, RULE_stmt);
		try {
			setState(29);
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
				setState(22);
				expr();
				setState(23);
				match(SEMI);
				}
				break;
			case RETURN:
				_localctx = new ReturnStmtContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(25);
				match(RETURN);
				setState(26);
				expr();
				setState(27);
				match(SEMI);
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
		enterRule(_localctx, 4, RULE_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(31);
			relational();
			setState(34);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==ASSIGN) {
				{
				setState(32);
				match(ASSIGN);
				setState(33);
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
		enterRule(_localctx, 6, RULE_relational);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(36);
			add();
			setState(49);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case EQ:
				{
				setState(37);
				match(EQ);
				setState(38);
				add();
				}
				break;
			case NE:
				{
				setState(39);
				match(NE);
				setState(40);
				add();
				}
				break;
			case LT:
				{
				setState(41);
				match(LT);
				setState(42);
				add();
				}
				break;
			case LE:
				{
				setState(43);
				match(LE);
				setState(44);
				add();
				}
				break;
			case GT:
				{
				setState(45);
				match(GT);
				setState(46);
				add();
				}
				break;
			case GE:
				{
				setState(47);
				match(GE);
				setState(48);
				add();
				}
				break;
			case ASSIGN:
			case RPAREN:
			case SEMI:
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
		enterRule(_localctx, 8, RULE_add);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(51);
			mul();
			setState(58);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ADD || _la==SUB) {
				{
				setState(56);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case ADD:
					{
					setState(52);
					match(ADD);
					setState(53);
					mul();
					}
					break;
				case SUB:
					{
					setState(54);
					match(SUB);
					setState(55);
					mul();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(60);
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
		enterRule(_localctx, 10, RULE_mul);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(61);
			unary();
			setState(68);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==MUL || _la==DIV) {
				{
				setState(66);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case MUL:
					{
					setState(62);
					match(MUL);
					setState(63);
					unary();
					}
					break;
				case DIV:
					{
					setState(64);
					match(DIV);
					setState(65);
					unary();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(70);
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
		enterRule(_localctx, 12, RULE_unary);
		int _la;
		try {
			setState(79);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,10,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(72);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ADD) {
					{
					setState(71);
					match(ADD);
					}
				}

				setState(74);
				primary();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(76);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==SUB) {
					{
					setState(75);
					match(SUB);
					}
				}

				setState(78);
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

	public final PrimaryContext primary() throws RecognitionException {
		PrimaryContext _localctx = new PrimaryContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_primary);
		try {
			setState(87);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM:
				_localctx = new NumPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(81);
				match(NUM);
				}
				break;
			case IDENT:
				_localctx = new IdentPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(82);
				match(IDENT);
				}
				break;
			case LPAREN:
				_localctx = new ParenthesizePrimaryContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(83);
				match(LPAREN);
				setState(84);
				expr();
				setState(85);
				match(RPAREN);
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

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3#\\\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\3\2\7\2\24\n\2\f\2"+
		"\16\2\27\13\2\3\3\3\3\3\3\3\3\3\3\3\3\3\3\5\3 \n\3\3\4\3\4\3\4\5\4%\n"+
		"\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5\5\5\64\n\5\3\6"+
		"\3\6\3\6\3\6\3\6\7\6;\n\6\f\6\16\6>\13\6\3\7\3\7\3\7\3\7\3\7\7\7E\n\7"+
		"\f\7\16\7H\13\7\3\b\5\bK\n\b\3\b\3\b\5\bO\n\b\3\b\5\bR\n\b\3\t\3\t\3\t"+
		"\3\t\3\t\3\t\5\tZ\n\t\3\t\2\2\n\2\4\6\b\n\f\16\20\2\2\2e\2\25\3\2\2\2"+
		"\4\37\3\2\2\2\6!\3\2\2\2\b&\3\2\2\2\n\65\3\2\2\2\f?\3\2\2\2\16Q\3\2\2"+
		"\2\20Y\3\2\2\2\22\24\5\4\3\2\23\22\3\2\2\2\24\27\3\2\2\2\25\23\3\2\2\2"+
		"\25\26\3\2\2\2\26\3\3\2\2\2\27\25\3\2\2\2\30\31\5\6\4\2\31\32\7\35\2\2"+
		"\32 \3\2\2\2\33\34\7\7\2\2\34\35\5\6\4\2\35\36\7\35\2\2\36 \3\2\2\2\37"+
		"\30\3\2\2\2\37\33\3\2\2\2 \5\3\2\2\2!$\5\b\5\2\"#\7\20\2\2#%\5\6\4\2$"+
		"\"\3\2\2\2$%\3\2\2\2%\7\3\2\2\2&\63\5\n\6\2\'(\7\25\2\2(\64\5\n\6\2)*"+
		"\7\26\2\2*\64\5\n\6\2+,\7\22\2\2,\64\5\n\6\2-.\7\23\2\2.\64\5\n\6\2/\60"+
		"\7\21\2\2\60\64\5\n\6\2\61\62\7\24\2\2\62\64\5\n\6\2\63\'\3\2\2\2\63)"+
		"\3\2\2\2\63+\3\2\2\2\63-\3\2\2\2\63/\3\2\2\2\63\61\3\2\2\2\63\64\3\2\2"+
		"\2\64\t\3\2\2\2\65<\5\f\7\2\66\67\7\13\2\2\67;\5\f\7\289\7\f\2\29;\5\f"+
		"\7\2:\66\3\2\2\2:8\3\2\2\2;>\3\2\2\2<:\3\2\2\2<=\3\2\2\2=\13\3\2\2\2>"+
		"<\3\2\2\2?F\5\16\b\2@A\7\r\2\2AE\5\16\b\2BC\7\16\2\2CE\5\16\b\2D@\3\2"+
		"\2\2DB\3\2\2\2EH\3\2\2\2FD\3\2\2\2FG\3\2\2\2G\r\3\2\2\2HF\3\2\2\2IK\7"+
		"\13\2\2JI\3\2\2\2JK\3\2\2\2KL\3\2\2\2LR\5\20\t\2MO\7\f\2\2NM\3\2\2\2N"+
		"O\3\2\2\2OP\3\2\2\2PR\5\20\t\2QJ\3\2\2\2QN\3\2\2\2R\17\3\2\2\2SZ\7#\2"+
		"\2TZ\7\"\2\2UV\7\27\2\2VW\5\6\4\2WX\7\30\2\2XZ\3\2\2\2YS\3\2\2\2YT\3\2"+
		"\2\2YU\3\2\2\2Z\21\3\2\2\2\16\25\37$\63:<DFJNQY";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}