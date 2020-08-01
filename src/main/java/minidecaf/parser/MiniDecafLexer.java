package minidecaf.parser;

// Generated from MiniDecafLexer.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MiniDecafLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	public static final String[] ruleNames = {
		"IF", "ELSE", "WHILE", "FOR", "RETURN", "SIZEOF", "INT", "CHAR", "ADD", 
		"SUB", "MUL", "DIV", "AND", "ASSIGN", "GT", "LT", "EQUAL", "LE", "GE", 
		"NOTEQUAL", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACK", "RBRACK", 
		"SEMI", "COMMA", "WS", "COMMENT", "LINE_COMMENT", "IDENT", "NUM"
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


	public MiniDecafLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MiniDecafLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2#\u00c3\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3\4\3\4\3\4\3\4\3"+
		"\5\3\5\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7"+
		"\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\r\3\r"+
		"\3\16\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\22\3\23\3\23\3\23"+
		"\3\24\3\24\3\24\3\25\3\25\3\25\3\26\3\26\3\27\3\27\3\30\3\30\3\31\3\31"+
		"\3\32\3\32\3\33\3\33\3\34\3\34\3\35\3\35\3\36\3\36\3\36\3\36\3\37\3\37"+
		"\3\37\3\37\7\37\u00a3\n\37\f\37\16\37\u00a6\13\37\3\37\3\37\3\37\3\37"+
		"\3\37\3 \3 \3 \3 \7 \u00b1\n \f \16 \u00b4\13 \3 \3 \3!\3!\7!\u00ba\n"+
		"!\f!\16!\u00bd\13!\3\"\6\"\u00c0\n\"\r\"\16\"\u00c1\3\u00a4\2#\3\3\5\4"+
		"\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22"+
		"#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C"+
		"#\3\2\7\5\2\13\f\16\17\"\"\4\2\f\f\17\17\5\2C\\aac|\6\2\62;C\\aac|\3\2"+
		"\62;\2\u00c6\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2"+
		"\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2"+
		"\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2"+
		"\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2"+
		"\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3"+
		"\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\3E\3\2\2"+
		"\2\5H\3\2\2\2\7M\3\2\2\2\tS\3\2\2\2\13W\3\2\2\2\r^\3\2\2\2\17e\3\2\2\2"+
		"\21i\3\2\2\2\23n\3\2\2\2\25p\3\2\2\2\27r\3\2\2\2\31t\3\2\2\2\33v\3\2\2"+
		"\2\35x\3\2\2\2\37z\3\2\2\2!|\3\2\2\2#~\3\2\2\2%\u0081\3\2\2\2\'\u0084"+
		"\3\2\2\2)\u0087\3\2\2\2+\u008a\3\2\2\2-\u008c\3\2\2\2/\u008e\3\2\2\2\61"+
		"\u0090\3\2\2\2\63\u0092\3\2\2\2\65\u0094\3\2\2\2\67\u0096\3\2\2\29\u0098"+
		"\3\2\2\2;\u009a\3\2\2\2=\u009e\3\2\2\2?\u00ac\3\2\2\2A\u00b7\3\2\2\2C"+
		"\u00bf\3\2\2\2EF\7k\2\2FG\7h\2\2G\4\3\2\2\2HI\7g\2\2IJ\7n\2\2JK\7u\2\2"+
		"KL\7g\2\2L\6\3\2\2\2MN\7y\2\2NO\7j\2\2OP\7k\2\2PQ\7n\2\2QR\7g\2\2R\b\3"+
		"\2\2\2ST\7h\2\2TU\7q\2\2UV\7t\2\2V\n\3\2\2\2WX\7t\2\2XY\7g\2\2YZ\7v\2"+
		"\2Z[\7w\2\2[\\\7t\2\2\\]\7p\2\2]\f\3\2\2\2^_\7u\2\2_`\7k\2\2`a\7|\2\2"+
		"ab\7g\2\2bc\7q\2\2cd\7h\2\2d\16\3\2\2\2ef\7k\2\2fg\7p\2\2gh\7v\2\2h\20"+
		"\3\2\2\2ij\7e\2\2jk\7j\2\2kl\7c\2\2lm\7t\2\2m\22\3\2\2\2no\7-\2\2o\24"+
		"\3\2\2\2pq\7/\2\2q\26\3\2\2\2rs\7,\2\2s\30\3\2\2\2tu\7\61\2\2u\32\3\2"+
		"\2\2vw\7(\2\2w\34\3\2\2\2xy\7?\2\2y\36\3\2\2\2z{\7@\2\2{ \3\2\2\2|}\7"+
		">\2\2}\"\3\2\2\2~\177\7?\2\2\177\u0080\7?\2\2\u0080$\3\2\2\2\u0081\u0082"+
		"\7>\2\2\u0082\u0083\7?\2\2\u0083&\3\2\2\2\u0084\u0085\7@\2\2\u0085\u0086"+
		"\7?\2\2\u0086(\3\2\2\2\u0087\u0088\7#\2\2\u0088\u0089\7?\2\2\u0089*\3"+
		"\2\2\2\u008a\u008b\7*\2\2\u008b,\3\2\2\2\u008c\u008d\7+\2\2\u008d.\3\2"+
		"\2\2\u008e\u008f\7}\2\2\u008f\60\3\2\2\2\u0090\u0091\7\177\2\2\u0091\62"+
		"\3\2\2\2\u0092\u0093\7]\2\2\u0093\64\3\2\2\2\u0094\u0095\7_\2\2\u0095"+
		"\66\3\2\2\2\u0096\u0097\7=\2\2\u00978\3\2\2\2\u0098\u0099\7.\2\2\u0099"+
		":\3\2\2\2\u009a\u009b\t\2\2\2\u009b\u009c\3\2\2\2\u009c\u009d\b\36\2\2"+
		"\u009d<\3\2\2\2\u009e\u009f\7\61\2\2\u009f\u00a0\7,\2\2\u00a0\u00a4\3"+
		"\2\2\2\u00a1\u00a3\13\2\2\2\u00a2\u00a1\3\2\2\2\u00a3\u00a6\3\2\2\2\u00a4"+
		"\u00a5\3\2\2\2\u00a4\u00a2\3\2\2\2\u00a5\u00a7\3\2\2\2\u00a6\u00a4\3\2"+
		"\2\2\u00a7\u00a8\7,\2\2\u00a8\u00a9\7\61\2\2\u00a9\u00aa\3\2\2\2\u00aa"+
		"\u00ab\b\37\2\2\u00ab>\3\2\2\2\u00ac\u00ad\7\61\2\2\u00ad\u00ae\7\61\2"+
		"\2\u00ae\u00b2\3\2\2\2\u00af\u00b1\n\3\2\2\u00b0\u00af\3\2\2\2\u00b1\u00b4"+
		"\3\2\2\2\u00b2\u00b0\3\2\2\2\u00b2\u00b3\3\2\2\2\u00b3\u00b5\3\2\2\2\u00b4"+
		"\u00b2\3\2\2\2\u00b5\u00b6\b \2\2\u00b6@\3\2\2\2\u00b7\u00bb\t\4\2\2\u00b8"+
		"\u00ba\t\5\2\2\u00b9\u00b8\3\2\2\2\u00ba\u00bd\3\2\2\2\u00bb\u00b9\3\2"+
		"\2\2\u00bb\u00bc\3\2\2\2\u00bcB\3\2\2\2\u00bd\u00bb\3\2\2\2\u00be\u00c0"+
		"\t\6\2\2\u00bf\u00be\3\2\2\2\u00c0\u00c1\3\2\2\2\u00c1\u00bf\3\2\2\2\u00c1"+
		"\u00c2\3\2\2\2\u00c2D\3\2\2\2\7\2\u00a4\u00b2\u00bb\u00c1\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}