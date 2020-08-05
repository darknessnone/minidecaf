# You need to use this script to regenerate the parser
# if you modify [MiniDecafParser.g4]

cd /home/ta/minidecaf/src/main/java/minidecaf/parser

java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool -no-listener -visitor MiniDecafParser.g4
{ echo -e 'package minidecaf.parser;\n'; cat MiniDecafParser.java; } > MiniDecafParser.java.new
mv MiniDecafParser.java.new MiniDecafParser.java

{ echo -e 'package minidecaf.parser;\n'; cat MiniDecafParserBaseVisitor.java; } > MiniDecafParserBaseVisitor.java.new
mv MiniDecafParserBaseVisitor.java.new MiniDecafParserBaseVisitor.java

{ echo -e 'package minidecaf.parser;\n'; cat MiniDecafParserVisitor.java; } > MiniDecafParserVisitor.java.new
mv MiniDecafParserVisitor.java.new MiniDecafParserVisitor.java

cd - > /dev/null