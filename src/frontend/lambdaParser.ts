// Generated from language/lambda.g4 by ANTLR 4.7.3-SNAPSHOT


import { ATN } from "antlr4ts/atn/ATN";
import { ATNDeserializer } from "antlr4ts/atn/ATNDeserializer";
import { FailedPredicateException } from "antlr4ts/FailedPredicateException";
import { NotNull } from "antlr4ts/Decorators";
import { NoViableAltException } from "antlr4ts/NoViableAltException";
import { Override } from "antlr4ts/Decorators";
import { Parser } from "antlr4ts/Parser";
import { ParserRuleContext } from "antlr4ts/ParserRuleContext";
import { ParserATNSimulator } from "antlr4ts/atn/ParserATNSimulator";
import { ParseTreeListener } from "antlr4ts/tree/ParseTreeListener";
import { ParseTreeVisitor } from "antlr4ts/tree/ParseTreeVisitor";
import { RecognitionException } from "antlr4ts/RecognitionException";
import { RuleContext } from "antlr4ts/RuleContext";
//import { RuleVersion } from "antlr4ts/RuleVersion";
import { TerminalNode } from "antlr4ts/tree/TerminalNode";
import { Token } from "antlr4ts/Token";
import { TokenStream } from "antlr4ts/TokenStream";
import { Vocabulary } from "antlr4ts/Vocabulary";
import { VocabularyImpl } from "antlr4ts/VocabularyImpl";

import * as Utils from "antlr4ts/misc/Utils";

import { lambdaListener } from "./lambdaListener";

export class lambdaParser extends Parser {
	public static readonly T__0 = 1;
	public static readonly T__1 = 2;
	public static readonly VAR = 3;
	public static readonly INT = 4;
	public static readonly WS = 5;
	public static readonly RULE_program = 0;
	public static readonly RULE_statement = 1;
	public static readonly RULE_let = 2;
	public static readonly RULE_show = 3;
	// tslint:disable:no-trailing-whitespace
	public static readonly ruleNames: string[] = [
		"program", "statement", "let", "show",
	];

	private static readonly _LITERAL_NAMES: Array<string | undefined> = [
		undefined, "'<-'", "'show'",
	];
	private static readonly _SYMBOLIC_NAMES: Array<string | undefined> = [
		undefined, undefined, undefined, "VAR", "INT", "WS",
	];
	public static readonly VOCABULARY: Vocabulary = new VocabularyImpl(lambdaParser._LITERAL_NAMES, lambdaParser._SYMBOLIC_NAMES, []);

	// @Override
	// @NotNull
	public get vocabulary(): Vocabulary {
		return lambdaParser.VOCABULARY;
	}
	// tslint:enable:no-trailing-whitespace

	// @Override
	public get grammarFileName(): string { return "lambda.g4"; }

	// @Override
	public get ruleNames(): string[] { return lambdaParser.ruleNames; }

	// @Override
	// public get serializedATN(): string { return lambdaParser._serializedATN; }

	constructor(input: TokenStream) {
		super(input);
		this._interp = new ParserATNSimulator(lambdaParser._ATN, this);
	}
	// @RuleVersion(0)
	public program(): ProgramContext {
		let _localctx: ProgramContext = new ProgramContext(this._ctx, this.state);
		this.enterRule(_localctx, 0, lambdaParser.RULE_program);
		let _la: number;
		try {
			this.enterOuterAlt(_localctx, 1);
			{
			this.state = 9;
			this._errHandler.sync(this);
			_la = this._input.LA(1);
			do {
				{
				{
				this.state = 8;
				this.statement();
				}
				}
				this.state = 11;
				this._errHandler.sync(this);
				_la = this._input.LA(1);
			} while (_la === lambdaParser.T__1 || _la === lambdaParser.VAR);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				_localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return _localctx;
	}
	// @RuleVersion(0)
	public statement(): StatementContext {
		let _localctx: StatementContext = new StatementContext(this._ctx, this.state);
		this.enterRule(_localctx, 2, lambdaParser.RULE_statement);
		try {
			this.state = 15;
			this._errHandler.sync(this);
			switch (this._input.LA(1)) {
			case lambdaParser.VAR:
				this.enterOuterAlt(_localctx, 1);
				{
				this.state = 13;
				this.let();
				}
				break;
			case lambdaParser.T__1:
				this.enterOuterAlt(_localctx, 2);
				{
				this.state = 14;
				this.show();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				_localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return _localctx;
	}
	// @RuleVersion(0)
	public let(): LetContext {
		let _localctx: LetContext = new LetContext(this._ctx, this.state);
		this.enterRule(_localctx, 4, lambdaParser.RULE_let);
		try {
			this.enterOuterAlt(_localctx, 1);
			{
			this.state = 17;
			this.match(lambdaParser.VAR);
			this.state = 18;
			this.match(lambdaParser.T__0);
			this.state = 19;
			this.match(lambdaParser.INT);
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				_localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return _localctx;
	}
	// @RuleVersion(0)
	public show(): ShowContext {
		let _localctx: ShowContext = new ShowContext(this._ctx, this.state);
		this.enterRule(_localctx, 6, lambdaParser.RULE_show);
		let _la: number;
		try {
			this.enterOuterAlt(_localctx, 1);
			{
			this.state = 21;
			this.match(lambdaParser.T__1);
			this.state = 22;
			_la = this._input.LA(1);
			if (!(_la === lambdaParser.VAR || _la === lambdaParser.INT)) {
			this._errHandler.recoverInline(this);
			} else {
				if (this._input.LA(1) === Token.EOF) {
					this.matchedEOF = true;
				}

				this._errHandler.reportMatch(this);
				this.consume();
			}
			}
		}
		catch (re) {
			if (re instanceof RecognitionException) {
				_localctx.exception = re;
				this._errHandler.reportError(this, re);
				this._errHandler.recover(this, re);
			} else {
				throw re;
			}
		}
		finally {
			this.exitRule();
		}
		return _localctx;
	}

	public static readonly _serializedATN: string =
		"\x03\uC91D\uCABA\u058D\uAFBA\u4F53\u0607\uEA8B\uC241\x03\x07\x1B\x04\x02" +
		"\t\x02\x04\x03\t\x03\x04\x04\t\x04\x04\x05\t\x05\x03\x02\x06\x02\f\n\x02" +
		"\r\x02\x0E\x02\r\x03\x03\x03\x03\x05\x03\x12\n\x03\x03\x04\x03\x04\x03" +
		"\x04\x03\x04\x03\x05\x03\x05\x03\x05\x03\x05\x02\x02\x02\x06\x02\x02\x04" +
		"\x02\x06\x02\b\x02\x02\x03\x03\x02\x05\x06\x02\x18\x02\v\x03\x02\x02\x02" +
		"\x04\x11\x03\x02\x02\x02\x06\x13\x03\x02\x02\x02\b\x17\x03\x02\x02\x02" +
		"\n\f\x05\x04\x03\x02\v\n\x03\x02\x02\x02\f\r\x03\x02\x02\x02\r\v\x03\x02" +
		"\x02\x02\r\x0E\x03\x02\x02\x02\x0E\x03\x03\x02\x02\x02\x0F\x12\x05\x06" +
		"\x04\x02\x10\x12\x05\b\x05\x02\x11\x0F\x03\x02\x02\x02\x11\x10\x03\x02" +
		"\x02\x02\x12\x05\x03\x02\x02\x02\x13\x14\x07\x05\x02\x02\x14\x15\x07\x03" +
		"\x02\x02\x15\x16\x07\x06\x02\x02\x16\x07\x03\x02\x02\x02\x17\x18\x07\x04" +
		"\x02\x02\x18\x19\t\x02\x02\x02\x19\t\x03\x02\x02\x02\x04\r\x11";
	public static __ATN: ATN;
	public static get _ATN(): ATN {
		if (!lambdaParser.__ATN) {
			lambdaParser.__ATN = new ATNDeserializer().deserialize(Utils.toCharArray(lambdaParser._serializedATN));
		}

		return lambdaParser.__ATN;
	}

}

export class ProgramContext extends ParserRuleContext {
	public statement(): StatementContext[];
	public statement(i: number): StatementContext;
	public statement(i?: number): StatementContext | StatementContext[] {
		if (i === undefined) {
			return this.getRuleContexts(StatementContext);
		} else {
			return this.getRuleContext(i, StatementContext);
		}
	}
	constructor(parent: ParserRuleContext | undefined, invokingState: number) {
		super(parent, invokingState);
	}
	// @Override
	// public get ruleIndex(): number { return lambdaParser.RULE_program; }
	// @Override
	public enterRule(listener: lambdaListener): void {
		if (listener.enterProgram) {
			listener.enterProgram(this);
		}
	}
	// @Override
	public exitRule(listener: lambdaListener): void {
		if (listener.exitProgram) {
			listener.exitProgram(this);
		}
	}
}


export class StatementContext extends ParserRuleContext {
	public let(): LetContext | undefined {
		return this.tryGetRuleContext(0, LetContext);
	}
	public show(): ShowContext | undefined {
		return this.tryGetRuleContext(0, ShowContext);
	}
	constructor(parent: ParserRuleContext | undefined, invokingState: number) {
		super(parent, invokingState);
	}
	// @Override
	// public get ruleIndex(): number { return lambdaParser.RULE_statement; }
	// @Override
	public enterRule(listener: lambdaListener): void {
		if (listener.enterStatement) {
			listener.enterStatement(this);
		}
	}
	// @Override
	public exitRule(listener: lambdaListener): void {
		if (listener.exitStatement) {
			listener.exitStatement(this);
		}
	}
}


export class LetContext extends ParserRuleContext {
	public VAR(): TerminalNode { return this.getToken(lambdaParser.VAR, 0); }
	public INT(): TerminalNode { return this.getToken(lambdaParser.INT, 0); }
	constructor(parent: ParserRuleContext | undefined, invokingState: number) {
		super(parent, invokingState);
	}
	// @Override
	// public get ruleIndex(): number { return lambdaParser.RULE_let; }
	// @Override
	public enterRule(listener: lambdaListener): void {
		if (listener.enterLet) {
			listener.enterLet(this);
		}
	}
	// @Override
	public exitRule(listener: lambdaListener): void {
		if (listener.exitLet) {
			listener.exitLet(this);
		}
	}
}


export class ShowContext extends ParserRuleContext {
	public INT(): TerminalNode | undefined { return this.tryGetToken(lambdaParser.INT, 0); }
	public VAR(): TerminalNode | undefined { return this.tryGetToken(lambdaParser.VAR, 0); }
	constructor(parent: ParserRuleContext | undefined, invokingState: number) {
		super(parent, invokingState);
	}
	// @Override
	// public get ruleIndex(): number { return lambdaParser.RULE_show; }
	// @Override
	public enterRule(listener: lambdaListener): void {
		if (listener.enterShow) {
			listener.enterShow(this);
		}
	}
	// @Override
	public exitRule(listener: lambdaListener): void {
		if (listener.exitShow) {
			listener.exitShow(this);
		}
	}
}


