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
		SUB=10, MUL=11, DIV=12, AND=13, ASSIGN=14, GT=15, LT=16, EQUAL=17, LE=18, 
		GE=19, NOTEQUAL=20, LPAREN=21, RPAREN=22, LBRACE=23, RBRACE=24, LBRACK=25, 
		RBRACK=26, SEMI=27, COMMA=28, WS=29, COMMENT=30, LINE_COMMENT=31, IDENT=32, 
		NUM=33;
	public static final int
		RULE_program = 0, RULE_expr = 1, RULE_mul = 2, RULE_unary = 3, RULE_primary = 4;
	public static final String[] ruleNames = {
		"program", "expr", "mul", "unary", "primary"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'if'", "'else'", "'while'", "'for'", "'return'", "'sizeof'", "'int'", 
		"'char'", "'+'", "'-'", "'*'", "'/'", "'&'", "'='", "'>'", "'<'", "'=='", 
		"'<='", "'>='", "'!='", "'('", "')'", "'{'", "'}'", "'['", "']'", "';'", 
		"','"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "IF", "ELSE", "WHILE", "FOR", "RETURN", "SIZEOF", "INT", "CHAR", 
		"ADD", "SUB", "MUL", "DIV", "AND", "ASSIGN", "GT", "LT", "EQUAL", "LE", 
		"GE", "NOTEQUAL", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
		"SEMI", "COMMA", "WS", "COMMENT", "LINE_COMMENT", "IDENT", "NUM"
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
		public ExprContext expr() {
			return getRuleContext(ExprContext.class,0);
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
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(10);
			expr();
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
		enterRule(_localctx, 2, RULE_expr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(12);
			mul();
			setState(19);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==ADD || _la==SUB) {
				{
				setState(17);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case ADD:
					{
					setState(13);
					match(ADD);
					setState(14);
					mul();
					}
					break;
				case SUB:
					{
					setState(15);
					match(SUB);
					setState(16);
					mul();
					}
					break;
				default:
					throw new NoViableAltException(this);
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
		enterRule(_localctx, 4, RULE_mul);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(22);
			unary();
			setState(29);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==MUL || _la==DIV) {
				{
				setState(27);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case MUL:
					{
					setState(23);
					match(MUL);
					setState(24);
					unary();
					}
					break;
				case DIV:
					{
					setState(25);
					match(DIV);
					setState(26);
					unary();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(31);
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
		enterRule(_localctx, 6, RULE_unary);
		int _la;
		try {
			setState(40);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,6,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(33);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ADD) {
					{
					setState(32);
					match(ADD);
					}
				}

				setState(35);
				primary();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(37);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==SUB) {
					{
					setState(36);
					match(SUB);
					}
				}

				setState(39);
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
		enterRule(_localctx, 8, RULE_primary);
		try {
			setState(47);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case NUM:
				_localctx = new NumPrimaryContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(42);
				match(NUM);
				}
				break;
			case LPAREN:
				_localctx = new ParenthesizePrimaryContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(43);
				match(LPAREN);
				setState(44);
				expr();
				setState(45);
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
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3#\64\4\2\t\2\4\3\t"+
		"\3\4\4\t\4\4\5\t\5\4\6\t\6\3\2\3\2\3\3\3\3\3\3\3\3\3\3\7\3\24\n\3\f\3"+
		"\16\3\27\13\3\3\4\3\4\3\4\3\4\3\4\7\4\36\n\4\f\4\16\4!\13\4\3\5\5\5$\n"+
		"\5\3\5\3\5\5\5(\n\5\3\5\5\5+\n\5\3\6\3\6\3\6\3\6\3\6\5\6\62\n\6\3\6\2"+
		"\2\7\2\4\6\b\n\2\2\2\66\2\f\3\2\2\2\4\16\3\2\2\2\6\30\3\2\2\2\b*\3\2\2"+
		"\2\n\61\3\2\2\2\f\r\5\4\3\2\r\3\3\2\2\2\16\25\5\6\4\2\17\20\7\13\2\2\20"+
		"\24\5\6\4\2\21\22\7\f\2\2\22\24\5\6\4\2\23\17\3\2\2\2\23\21\3\2\2\2\24"+
		"\27\3\2\2\2\25\23\3\2\2\2\25\26\3\2\2\2\26\5\3\2\2\2\27\25\3\2\2\2\30"+
		"\37\5\b\5\2\31\32\7\r\2\2\32\36\5\b\5\2\33\34\7\16\2\2\34\36\5\b\5\2\35"+
		"\31\3\2\2\2\35\33\3\2\2\2\36!\3\2\2\2\37\35\3\2\2\2\37 \3\2\2\2 \7\3\2"+
		"\2\2!\37\3\2\2\2\"$\7\13\2\2#\"\3\2\2\2#$\3\2\2\2$%\3\2\2\2%+\5\n\6\2"+
		"&(\7\f\2\2\'&\3\2\2\2\'(\3\2\2\2()\3\2\2\2)+\5\n\6\2*#\3\2\2\2*\'\3\2"+
		"\2\2+\t\3\2\2\2,\62\7#\2\2-.\7\27\2\2./\5\4\3\2/\60\7\30\2\2\60\62\3\2"+
		"\2\2\61,\3\2\2\2\61-\3\2\2\2\62\13\3\2\2\2\n\23\25\35\37#\'*\61";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}