# You need to use this script to regenerate the parser
# if you modify [MiniDecafParser.g4]

cd /home/ta/minidecaf/src/main/java/minidecaf/parser

java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool MiniDecafLexer.g4

{ echo -e 'package minidecaf.parser;\n'; cat MiniDecafLexer.java; } > MiniDecafLexer.java.new
mv MiniDecafLexer.java.new MiniDecafLexer.java

java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool -no-listener -visitor MiniDecafParser.g4
for filename in MiniDecafParser.java MiniDecafParserBaseVisitor.java MiniDecafParserVisitor.java
do
{ echo -e 'package minidecaf.parser;\n'; cat $filename; } > $filename.new
mv $filename.new $filename
done

cd - > /dev/null