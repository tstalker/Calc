# Calc
# grammar

Program:
	END // end of input
	ExprList END

ExprList: // Expression list
	Expression PRINT // ;
	Expression PRINT ExprList

Expression:
	Expression + Term
	Expression - Term

Term:
	Term * Primary
	Term / Primary
	Primary

Primary:
	NUMBER
	NAME
	NAME = Expression
	-Primary
	(Expression)
