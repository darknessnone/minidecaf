parser grammar MDParser;

options {
    tokenVocab = MDLexer;
}

@parser::postinclude {

#include <string>

#include "ASTNode.h"

}

program returns [std::shared_ptr<ASTNode> node]
        : stmtSeq EOF
          {
            $node = $stmtSeq.node;
          }
        ;

stmtSeq returns [std::shared_ptr<ASTNode> node]
        : stmt
          {
            $node = StmtSeqNode::make({$stmt.node});
          }
        | part=stmtSeq stmt
          {
            $node = $part.node;
            CHECK_NODE_TYPE($node, StmtSeq);
            static_cast<StmtSeqNode*>($node.get())->stmts_.push_back($stmt.node);
          }
        ;

stmt    returns [std::shared_ptr<ASTNode> node]
        : expr ';'
          {
            $node = $expr.node;
          }
        | Identifier '=' expr ';'
          {
            $node = AssignNode::make(VarNode::make($Identifier.text), $expr.node);
          }
        ;

expr    returns [std::shared_ptr<ASTNode> node]
        : Integer
          {
            $node = IntegerNode::make(std::stoi($Integer.text));
          }
        | Identifier
          {
            $node = VarNode::make($Identifier.text);
          }
        | '(' expr ')'
          {
            $node = $expr.node;
          }
        | '-' expr
          {
            $node = SubNode::make(IntegerNode::make(0), $expr.node);
          }
        | '+' expr
          {
            $node = $expr.node;
          }
        | lhs=expr op=('*' | '/') rhs=expr
          {
            if ($op.text == "*") {
                $node = MulNode::make($lhs.node, $rhs.node);
            } else {
                $node = DivNode::make($lhs.node, $rhs.node);
            }
          }
        | lhs=expr op=('+' | '-') rhs=expr
          {
            if ($op.text == "+") {
                $node = AddNode::make($lhs.node, $rhs.node);
            } else {
                $node = SubNode::make($lhs.node, $rhs.node);
            }
          }
        | lhs=expr op=('<' | '>' | '<=' | '>=' | '==' | '!=') rhs=expr
          {
            if ($op.text == "<") {
                $node = LTNode::make($lhs.node, $rhs.node);
            } else if ($op.text == ">") {
                $node = GTNode::make($lhs.node, $rhs.node);
            } else if ($op.text == "<=") {
                $node = LENode::make($lhs.node, $rhs.node);
            } else if ($op.text == ">=") {
                $node = GENode::make($lhs.node, $rhs.node);
            } else if ($op.text == "==") {
                $node = EQNode::make($lhs.node, $rhs.node);
            } else if ($op.text == "!=") {
                $node = NENode::make($lhs.node, $rhs.node);
            }
          }
        ;
