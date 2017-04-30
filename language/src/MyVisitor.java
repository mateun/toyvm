/**
 * Created by martingruscher on 29/04/2017.
 */
public class MyVisitor<String> extends ExprBaseVisitor {

    @Override
    public String visitModule(ExprParser.ModuleContext ctx) {
        visitChildren(ctx);
        System.out.println("children of prog: " + ctx.getChildCount());
        return null;
    }

    @Override
    public String visitAddition(ExprParser.AdditionContext ctx) {
        visitChildren(ctx);
        System.out.println("addi");

        return null;
    }

    @Override
    public String visitSubtraction(ExprParser.SubtractionContext ctx) {
        visitChildren(ctx);
        System.out.println("subi");
        return null;
    }

    @Override
    public String visitMultiplication(ExprParser.MultiplicationContext ctx) {
        visitChildren(ctx);
        System.out.println("muli");
        return null;
    }

    @Override
    public String visitDivision(ExprParser.DivisionContext ctx) {
        visitChildren(ctx);
        System.out.println("divi");
        return null;
    }

    @Override
    public String visitTermonly(ExprParser.TermonlyContext ctx) {
        visitChildren(ctx);
        return null;
    }

    @Override
    public String visitFactoronly(ExprParser.FactoronlyContext ctx) {
        visitChildren(ctx);
        return null;
    }

    @Override
    public String visitFactor(ExprParser.FactorContext ctx) {
        System.out.println("consti " + ctx.getChild(0));
        return null;
    }

    @Override
    public String visitAss(ExprParser.AssContext ctx) {
        visitChildren(ctx);
        System.out.println("assignment: " + ctx.getChild(0).getText());
        return null;
    }


}
