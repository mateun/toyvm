import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;

import java.io.StringReader;

class MyCompiler extends ExprBaseListener {

	public static void main(String[] args)  {
		String sentence = "foo=23\n12+8-3*34\n";
        ExprLexer lexer = new ExprLexer(new ANTLRInputStream(sentence));

		CommonTokenStream tokens = new CommonTokenStream(lexer);
		ExprParser parser = new ExprParser(tokens);
		ParseTree tree = parser.module();

		//ParseTreeWalker walker = new ParseTreeWalker();
		//walker.walk(new MyCompiler(), tree);

        MyVisitor visitor = new MyVisitor();
        visitor.visit(tree);

		System.out.println("hello world\n");
	}


}


