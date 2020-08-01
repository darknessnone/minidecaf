
// Generated from MiniDecaf.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "MiniDecafParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by MiniDecafParser.
 */
class  MiniDecafListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterPrimaryExpression(MiniDecafParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(MiniDecafParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterGenericSelection(MiniDecafParser::GenericSelectionContext *ctx) = 0;
  virtual void exitGenericSelection(MiniDecafParser::GenericSelectionContext *ctx) = 0;

  virtual void enterGenericAssocList(MiniDecafParser::GenericAssocListContext *ctx) = 0;
  virtual void exitGenericAssocList(MiniDecafParser::GenericAssocListContext *ctx) = 0;

  virtual void enterGenericAssociation(MiniDecafParser::GenericAssociationContext *ctx) = 0;
  virtual void exitGenericAssociation(MiniDecafParser::GenericAssociationContext *ctx) = 0;

  virtual void enterPostfixExpression(MiniDecafParser::PostfixExpressionContext *ctx) = 0;
  virtual void exitPostfixExpression(MiniDecafParser::PostfixExpressionContext *ctx) = 0;

  virtual void enterArgumentExpressionList(MiniDecafParser::ArgumentExpressionListContext *ctx) = 0;
  virtual void exitArgumentExpressionList(MiniDecafParser::ArgumentExpressionListContext *ctx) = 0;

  virtual void enterUnaryExpression(MiniDecafParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(MiniDecafParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterUnaryOperator(MiniDecafParser::UnaryOperatorContext *ctx) = 0;
  virtual void exitUnaryOperator(MiniDecafParser::UnaryOperatorContext *ctx) = 0;

  virtual void enterCastExpression(MiniDecafParser::CastExpressionContext *ctx) = 0;
  virtual void exitCastExpression(MiniDecafParser::CastExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(MiniDecafParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(MiniDecafParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(MiniDecafParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(MiniDecafParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterShiftExpression(MiniDecafParser::ShiftExpressionContext *ctx) = 0;
  virtual void exitShiftExpression(MiniDecafParser::ShiftExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(MiniDecafParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(MiniDecafParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(MiniDecafParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(MiniDecafParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterAndExpression(MiniDecafParser::AndExpressionContext *ctx) = 0;
  virtual void exitAndExpression(MiniDecafParser::AndExpressionContext *ctx) = 0;

  virtual void enterExclusiveOrExpression(MiniDecafParser::ExclusiveOrExpressionContext *ctx) = 0;
  virtual void exitExclusiveOrExpression(MiniDecafParser::ExclusiveOrExpressionContext *ctx) = 0;

  virtual void enterInclusiveOrExpression(MiniDecafParser::InclusiveOrExpressionContext *ctx) = 0;
  virtual void exitInclusiveOrExpression(MiniDecafParser::InclusiveOrExpressionContext *ctx) = 0;

  virtual void enterLogicalAndExpression(MiniDecafParser::LogicalAndExpressionContext *ctx) = 0;
  virtual void exitLogicalAndExpression(MiniDecafParser::LogicalAndExpressionContext *ctx) = 0;

  virtual void enterLogicalOrExpression(MiniDecafParser::LogicalOrExpressionContext *ctx) = 0;
  virtual void exitLogicalOrExpression(MiniDecafParser::LogicalOrExpressionContext *ctx) = 0;

  virtual void enterConditionalExpression(MiniDecafParser::ConditionalExpressionContext *ctx) = 0;
  virtual void exitConditionalExpression(MiniDecafParser::ConditionalExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(MiniDecafParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(MiniDecafParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterAssignmentOperator(MiniDecafParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(MiniDecafParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterExpression(MiniDecafParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(MiniDecafParser::ExpressionContext *ctx) = 0;

  virtual void enterConstantExpression(MiniDecafParser::ConstantExpressionContext *ctx) = 0;
  virtual void exitConstantExpression(MiniDecafParser::ConstantExpressionContext *ctx) = 0;

  virtual void enterDeclaration(MiniDecafParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(MiniDecafParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers(MiniDecafParser::DeclarationSpecifiersContext *ctx) = 0;
  virtual void exitDeclarationSpecifiers(MiniDecafParser::DeclarationSpecifiersContext *ctx) = 0;

  virtual void enterDeclarationSpecifiers2(MiniDecafParser::DeclarationSpecifiers2Context *ctx) = 0;
  virtual void exitDeclarationSpecifiers2(MiniDecafParser::DeclarationSpecifiers2Context *ctx) = 0;

  virtual void enterDeclarationSpecifier(MiniDecafParser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(MiniDecafParser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterInitDeclaratorList(MiniDecafParser::InitDeclaratorListContext *ctx) = 0;
  virtual void exitInitDeclaratorList(MiniDecafParser::InitDeclaratorListContext *ctx) = 0;

  virtual void enterInitDeclarator(MiniDecafParser::InitDeclaratorContext *ctx) = 0;
  virtual void exitInitDeclarator(MiniDecafParser::InitDeclaratorContext *ctx) = 0;

  virtual void enterStorageClassSpecifier(MiniDecafParser::StorageClassSpecifierContext *ctx) = 0;
  virtual void exitStorageClassSpecifier(MiniDecafParser::StorageClassSpecifierContext *ctx) = 0;

  virtual void enterTypeSpecifier(MiniDecafParser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(MiniDecafParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterStructOrUnionSpecifier(MiniDecafParser::StructOrUnionSpecifierContext *ctx) = 0;
  virtual void exitStructOrUnionSpecifier(MiniDecafParser::StructOrUnionSpecifierContext *ctx) = 0;

  virtual void enterStructOrUnion(MiniDecafParser::StructOrUnionContext *ctx) = 0;
  virtual void exitStructOrUnion(MiniDecafParser::StructOrUnionContext *ctx) = 0;

  virtual void enterStructDeclarationList(MiniDecafParser::StructDeclarationListContext *ctx) = 0;
  virtual void exitStructDeclarationList(MiniDecafParser::StructDeclarationListContext *ctx) = 0;

  virtual void enterStructDeclaration(MiniDecafParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(MiniDecafParser::StructDeclarationContext *ctx) = 0;

  virtual void enterSpecifierQualifierList(MiniDecafParser::SpecifierQualifierListContext *ctx) = 0;
  virtual void exitSpecifierQualifierList(MiniDecafParser::SpecifierQualifierListContext *ctx) = 0;

  virtual void enterStructDeclaratorList(MiniDecafParser::StructDeclaratorListContext *ctx) = 0;
  virtual void exitStructDeclaratorList(MiniDecafParser::StructDeclaratorListContext *ctx) = 0;

  virtual void enterStructDeclarator(MiniDecafParser::StructDeclaratorContext *ctx) = 0;
  virtual void exitStructDeclarator(MiniDecafParser::StructDeclaratorContext *ctx) = 0;

  virtual void enterEnumSpecifier(MiniDecafParser::EnumSpecifierContext *ctx) = 0;
  virtual void exitEnumSpecifier(MiniDecafParser::EnumSpecifierContext *ctx) = 0;

  virtual void enterEnumeratorList(MiniDecafParser::EnumeratorListContext *ctx) = 0;
  virtual void exitEnumeratorList(MiniDecafParser::EnumeratorListContext *ctx) = 0;

  virtual void enterEnumerator(MiniDecafParser::EnumeratorContext *ctx) = 0;
  virtual void exitEnumerator(MiniDecafParser::EnumeratorContext *ctx) = 0;

  virtual void enterEnumerationConstant(MiniDecafParser::EnumerationConstantContext *ctx) = 0;
  virtual void exitEnumerationConstant(MiniDecafParser::EnumerationConstantContext *ctx) = 0;

  virtual void enterAtomicTypeSpecifier(MiniDecafParser::AtomicTypeSpecifierContext *ctx) = 0;
  virtual void exitAtomicTypeSpecifier(MiniDecafParser::AtomicTypeSpecifierContext *ctx) = 0;

  virtual void enterTypeQualifier(MiniDecafParser::TypeQualifierContext *ctx) = 0;
  virtual void exitTypeQualifier(MiniDecafParser::TypeQualifierContext *ctx) = 0;

  virtual void enterFunctionSpecifier(MiniDecafParser::FunctionSpecifierContext *ctx) = 0;
  virtual void exitFunctionSpecifier(MiniDecafParser::FunctionSpecifierContext *ctx) = 0;

  virtual void enterAlignmentSpecifier(MiniDecafParser::AlignmentSpecifierContext *ctx) = 0;
  virtual void exitAlignmentSpecifier(MiniDecafParser::AlignmentSpecifierContext *ctx) = 0;

  virtual void enterDeclarator(MiniDecafParser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(MiniDecafParser::DeclaratorContext *ctx) = 0;

  virtual void enterDirectDeclarator(MiniDecafParser::DirectDeclaratorContext *ctx) = 0;
  virtual void exitDirectDeclarator(MiniDecafParser::DirectDeclaratorContext *ctx) = 0;

  virtual void enterGccDeclaratorExtension(MiniDecafParser::GccDeclaratorExtensionContext *ctx) = 0;
  virtual void exitGccDeclaratorExtension(MiniDecafParser::GccDeclaratorExtensionContext *ctx) = 0;

  virtual void enterGccAttributeSpecifier(MiniDecafParser::GccAttributeSpecifierContext *ctx) = 0;
  virtual void exitGccAttributeSpecifier(MiniDecafParser::GccAttributeSpecifierContext *ctx) = 0;

  virtual void enterGccAttributeList(MiniDecafParser::GccAttributeListContext *ctx) = 0;
  virtual void exitGccAttributeList(MiniDecafParser::GccAttributeListContext *ctx) = 0;

  virtual void enterGccAttribute(MiniDecafParser::GccAttributeContext *ctx) = 0;
  virtual void exitGccAttribute(MiniDecafParser::GccAttributeContext *ctx) = 0;

  virtual void enterNestedParenthesesBlock(MiniDecafParser::NestedParenthesesBlockContext *ctx) = 0;
  virtual void exitNestedParenthesesBlock(MiniDecafParser::NestedParenthesesBlockContext *ctx) = 0;

  virtual void enterPointer(MiniDecafParser::PointerContext *ctx) = 0;
  virtual void exitPointer(MiniDecafParser::PointerContext *ctx) = 0;

  virtual void enterTypeQualifierList(MiniDecafParser::TypeQualifierListContext *ctx) = 0;
  virtual void exitTypeQualifierList(MiniDecafParser::TypeQualifierListContext *ctx) = 0;

  virtual void enterParameterTypeList(MiniDecafParser::ParameterTypeListContext *ctx) = 0;
  virtual void exitParameterTypeList(MiniDecafParser::ParameterTypeListContext *ctx) = 0;

  virtual void enterParameterList(MiniDecafParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(MiniDecafParser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(MiniDecafParser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(MiniDecafParser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterIdentifierList(MiniDecafParser::IdentifierListContext *ctx) = 0;
  virtual void exitIdentifierList(MiniDecafParser::IdentifierListContext *ctx) = 0;

  virtual void enterTypeName(MiniDecafParser::TypeNameContext *ctx) = 0;
  virtual void exitTypeName(MiniDecafParser::TypeNameContext *ctx) = 0;

  virtual void enterAbstractDeclarator(MiniDecafParser::AbstractDeclaratorContext *ctx) = 0;
  virtual void exitAbstractDeclarator(MiniDecafParser::AbstractDeclaratorContext *ctx) = 0;

  virtual void enterDirectAbstractDeclarator(MiniDecafParser::DirectAbstractDeclaratorContext *ctx) = 0;
  virtual void exitDirectAbstractDeclarator(MiniDecafParser::DirectAbstractDeclaratorContext *ctx) = 0;

  virtual void enterTypedefName(MiniDecafParser::TypedefNameContext *ctx) = 0;
  virtual void exitTypedefName(MiniDecafParser::TypedefNameContext *ctx) = 0;

  virtual void enterInitializer(MiniDecafParser::InitializerContext *ctx) = 0;
  virtual void exitInitializer(MiniDecafParser::InitializerContext *ctx) = 0;

  virtual void enterInitializerList(MiniDecafParser::InitializerListContext *ctx) = 0;
  virtual void exitInitializerList(MiniDecafParser::InitializerListContext *ctx) = 0;

  virtual void enterDesignation(MiniDecafParser::DesignationContext *ctx) = 0;
  virtual void exitDesignation(MiniDecafParser::DesignationContext *ctx) = 0;

  virtual void enterDesignatorList(MiniDecafParser::DesignatorListContext *ctx) = 0;
  virtual void exitDesignatorList(MiniDecafParser::DesignatorListContext *ctx) = 0;

  virtual void enterDesignator(MiniDecafParser::DesignatorContext *ctx) = 0;
  virtual void exitDesignator(MiniDecafParser::DesignatorContext *ctx) = 0;

  virtual void enterStaticAssertDeclaration(MiniDecafParser::StaticAssertDeclarationContext *ctx) = 0;
  virtual void exitStaticAssertDeclaration(MiniDecafParser::StaticAssertDeclarationContext *ctx) = 0;

  virtual void enterStatement(MiniDecafParser::StatementContext *ctx) = 0;
  virtual void exitStatement(MiniDecafParser::StatementContext *ctx) = 0;

  virtual void enterLabeledStatement(MiniDecafParser::LabeledStatementContext *ctx) = 0;
  virtual void exitLabeledStatement(MiniDecafParser::LabeledStatementContext *ctx) = 0;

  virtual void enterCompoundStatement(MiniDecafParser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(MiniDecafParser::CompoundStatementContext *ctx) = 0;

  virtual void enterBlockItemList(MiniDecafParser::BlockItemListContext *ctx) = 0;
  virtual void exitBlockItemList(MiniDecafParser::BlockItemListContext *ctx) = 0;

  virtual void enterBlockItem(MiniDecafParser::BlockItemContext *ctx) = 0;
  virtual void exitBlockItem(MiniDecafParser::BlockItemContext *ctx) = 0;

  virtual void enterExpressionStatement(MiniDecafParser::ExpressionStatementContext *ctx) = 0;
  virtual void exitExpressionStatement(MiniDecafParser::ExpressionStatementContext *ctx) = 0;

  virtual void enterSelectionStatement(MiniDecafParser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(MiniDecafParser::SelectionStatementContext *ctx) = 0;

  virtual void enterIterationStatement(MiniDecafParser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(MiniDecafParser::IterationStatementContext *ctx) = 0;

  virtual void enterForCondition(MiniDecafParser::ForConditionContext *ctx) = 0;
  virtual void exitForCondition(MiniDecafParser::ForConditionContext *ctx) = 0;

  virtual void enterForDeclaration(MiniDecafParser::ForDeclarationContext *ctx) = 0;
  virtual void exitForDeclaration(MiniDecafParser::ForDeclarationContext *ctx) = 0;

  virtual void enterForExpression(MiniDecafParser::ForExpressionContext *ctx) = 0;
  virtual void exitForExpression(MiniDecafParser::ForExpressionContext *ctx) = 0;

  virtual void enterJumpStatement(MiniDecafParser::JumpStatementContext *ctx) = 0;
  virtual void exitJumpStatement(MiniDecafParser::JumpStatementContext *ctx) = 0;

  virtual void enterCompilationUnit(MiniDecafParser::CompilationUnitContext *ctx) = 0;
  virtual void exitCompilationUnit(MiniDecafParser::CompilationUnitContext *ctx) = 0;

  virtual void enterTranslationUnit(MiniDecafParser::TranslationUnitContext *ctx) = 0;
  virtual void exitTranslationUnit(MiniDecafParser::TranslationUnitContext *ctx) = 0;

  virtual void enterExternalDeclaration(MiniDecafParser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(MiniDecafParser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(MiniDecafParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(MiniDecafParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterDeclarationList(MiniDecafParser::DeclarationListContext *ctx) = 0;
  virtual void exitDeclarationList(MiniDecafParser::DeclarationListContext *ctx) = 0;


};

