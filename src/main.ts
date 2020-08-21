import { ANTLRInputStream, CommonTokenStream } from 'antlr4ts';
import * as fs from 'fs'
import * as path from 'path'

import {
    lambdaListener,
    lambdaLexer,
    lambdaParser,
    // lambdaVisitor
} from './frontend/frontend'

function read(filename: string): string {
    const filepath = path.join(__dirname, filename)
    return fs.readFileSync(filepath).toString()
}

// Create the lexer and parser
let inputStream = new ANTLRInputStream(read('../test.lambda'));
let lexer = new lambdaLexer(inputStream);
let tokenStream = new CommonTokenStream(lexer);
let parser = new lambdaParser(tokenStream);

// Parse the input, where `compilationUnit` is whatever entry point you defined
let tree = parser.program();