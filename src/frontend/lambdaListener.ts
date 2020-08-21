// Generated from language/lambda.g4 by ANTLR 4.7.3-SNAPSHOT


import { ParseTreeListener } from "antlr4ts/tree/ParseTreeListener";

import { ProgramContext } from "./lambdaParser";
import { StatementContext } from "./lambdaParser";
import { LetContext } from "./lambdaParser";
import { ShowContext } from "./lambdaParser";


/**
 * This interface defines a complete listener for a parse tree produced by
 * `lambdaParser`.
 */
export interface lambdaListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by `lambdaParser.program`.
	 * @param ctx the parse tree
	 */
	enterProgram?: (ctx: ProgramContext) => void;
	/**
	 * Exit a parse tree produced by `lambdaParser.program`.
	 * @param ctx the parse tree
	 */
	exitProgram?: (ctx: ProgramContext) => void;

	/**
	 * Enter a parse tree produced by `lambdaParser.statement`.
	 * @param ctx the parse tree
	 */
	enterStatement?: (ctx: StatementContext) => void;
	/**
	 * Exit a parse tree produced by `lambdaParser.statement`.
	 * @param ctx the parse tree
	 */
	exitStatement?: (ctx: StatementContext) => void;

	/**
	 * Enter a parse tree produced by `lambdaParser.let`.
	 * @param ctx the parse tree
	 */
	enterLet?: (ctx: LetContext) => void;
	/**
	 * Exit a parse tree produced by `lambdaParser.let`.
	 * @param ctx the parse tree
	 */
	exitLet?: (ctx: LetContext) => void;

	/**
	 * Enter a parse tree produced by `lambdaParser.show`.
	 * @param ctx the parse tree
	 */
	enterShow?: (ctx: ShowContext) => void;
	/**
	 * Exit a parse tree produced by `lambdaParser.show`.
	 * @param ctx the parse tree
	 */
	exitShow?: (ctx: ShowContext) => void;
}

