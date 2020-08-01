
// Generated from MiniDecaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MiniDecafParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MiniDecafParser.
 */
class  MiniDecafVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MiniDecafParser.
   */
    virtual antlrcpp::Any visitPrimaryExpression(MiniDecafParser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitGenericSelection(MiniDecafParser::GenericSelectionContext *context) = 0;

    virtual antlrcpp::Any visitGenericAssocList(MiniDecafParser::GenericAssocListContext *context) = 0;

    virtual antlrcpp::Any visitGenericAssociation(MiniDecafParser::GenericAssociationContext *context) = 0;

    virtual antlrcpp::Any visitPostfixExpression(MiniDecafParser::PostfixExpressionContext *context) = 0;

    virtual antlrcpp::Any visitArgumentExpressionList(MiniDecafParser::ArgumentExpressionListContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(MiniDecafParser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperator(MiniDecafParser::UnaryOperatorContext *context) = 0;

    virtual antlrcpp::Any visitCastExpression(MiniDecafParser::CastExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(MiniDecafParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(MiniDecafParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitShiftExpression(MiniDecafParser::ShiftExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(MiniDecafParser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(MiniDecafParser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAndExpression(MiniDecafParser::AndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitExclusiveOrExpression(MiniDecafParser::ExclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitInclusiveOrExpression(MiniDecafParser::InclusiveOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalAndExpression(MiniDecafParser::LogicalAndExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOrExpression(MiniDecafParser::LogicalOrExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConditionalExpression(MiniDecafParser::ConditionalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(MiniDecafParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(MiniDecafParser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitExpression(MiniDecafParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitConstantExpression(MiniDecafParser::ConstantExpressionContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(MiniDecafParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers(MiniDecafParser::DeclarationSpecifiersContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifiers2(MiniDecafParser::DeclarationSpecifiers2Context *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(MiniDecafParser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclaratorList(MiniDecafParser::InitDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclarator(MiniDecafParser::InitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitStorageClassSpecifier(MiniDecafParser::StorageClassSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(MiniDecafParser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitStructOrUnionSpecifier(MiniDecafParser::StructOrUnionSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitStructOrUnion(MiniDecafParser::StructOrUnionContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarationList(MiniDecafParser::StructDeclarationListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaration(MiniDecafParser::StructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitSpecifierQualifierList(MiniDecafParser::SpecifierQualifierListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaratorList(MiniDecafParser::StructDeclaratorListContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarator(MiniDecafParser::StructDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitEnumSpecifier(MiniDecafParser::EnumSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitEnumeratorList(MiniDecafParser::EnumeratorListContext *context) = 0;

    virtual antlrcpp::Any visitEnumerator(MiniDecafParser::EnumeratorContext *context) = 0;

    virtual antlrcpp::Any visitEnumerationConstant(MiniDecafParser::EnumerationConstantContext *context) = 0;

    virtual antlrcpp::Any visitAtomicTypeSpecifier(MiniDecafParser::AtomicTypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeQualifier(MiniDecafParser::TypeQualifierContext *context) = 0;

    virtual antlrcpp::Any visitFunctionSpecifier(MiniDecafParser::FunctionSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitAlignmentSpecifier(MiniDecafParser::AlignmentSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(MiniDecafParser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectDeclarator(MiniDecafParser::DirectDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitGccDeclaratorExtension(MiniDecafParser::GccDeclaratorExtensionContext *context) = 0;

    virtual antlrcpp::Any visitGccAttributeSpecifier(MiniDecafParser::GccAttributeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitGccAttributeList(MiniDecafParser::GccAttributeListContext *context) = 0;

    virtual antlrcpp::Any visitGccAttribute(MiniDecafParser::GccAttributeContext *context) = 0;

    virtual antlrcpp::Any visitNestedParenthesesBlock(MiniDecafParser::NestedParenthesesBlockContext *context) = 0;

    virtual antlrcpp::Any visitPointer(MiniDecafParser::PointerContext *context) = 0;

    virtual antlrcpp::Any visitTypeQualifierList(MiniDecafParser::TypeQualifierListContext *context) = 0;

    virtual antlrcpp::Any visitParameterTypeList(MiniDecafParser::ParameterTypeListContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(MiniDecafParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(MiniDecafParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitIdentifierList(MiniDecafParser::IdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitTypeName(MiniDecafParser::TypeNameContext *context) = 0;

    virtual antlrcpp::Any visitAbstractDeclarator(MiniDecafParser::AbstractDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitDirectAbstractDeclarator(MiniDecafParser::DirectAbstractDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitTypedefName(MiniDecafParser::TypedefNameContext *context) = 0;

    virtual antlrcpp::Any visitInitializer(MiniDecafParser::InitializerContext *context) = 0;

    virtual antlrcpp::Any visitInitializerList(MiniDecafParser::InitializerListContext *context) = 0;

    virtual antlrcpp::Any visitDesignation(MiniDecafParser::DesignationContext *context) = 0;

    virtual antlrcpp::Any visitDesignatorList(MiniDecafParser::DesignatorListContext *context) = 0;

    virtual antlrcpp::Any visitDesignator(MiniDecafParser::DesignatorContext *context) = 0;

    virtual antlrcpp::Any visitStaticAssertDeclaration(MiniDecafParser::StaticAssertDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitStatement(MiniDecafParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLabeledStatement(MiniDecafParser::LabeledStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(MiniDecafParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitBlockItemList(MiniDecafParser::BlockItemListContext *context) = 0;

    virtual antlrcpp::Any visitBlockItem(MiniDecafParser::BlockItemContext *context) = 0;

    virtual antlrcpp::Any visitExpressionStatement(MiniDecafParser::ExpressionStatementContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(MiniDecafParser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(MiniDecafParser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitForCondition(MiniDecafParser::ForConditionContext *context) = 0;

    virtual antlrcpp::Any visitForDeclaration(MiniDecafParser::ForDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitForExpression(MiniDecafParser::ForExpressionContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(MiniDecafParser::JumpStatementContext *context) = 0;

    virtual antlrcpp::Any visitCompilationUnit(MiniDecafParser::CompilationUnitContext *context) = 0;

    virtual antlrcpp::Any visitTranslationUnit(MiniDecafParser::TranslationUnitContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(MiniDecafParser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(MiniDecafParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationList(MiniDecafParser::DeclarationListContext *context) = 0;


};

