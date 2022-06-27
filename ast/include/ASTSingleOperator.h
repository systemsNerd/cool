#ifndef ASTSINGLEOPERATOR_H_
#define ASTSINGLEOPERATOR_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTSingleOperator : public ASTNode {

public:
  virtual ~ASTSingleOperator() {}
};

typedef std::unique_ptr<ASTSingleOperator> ASTSingleOperatorPtr;
}
#endif /* ASTSINGLEOPERATOR_H_ */
