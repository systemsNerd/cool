#ifndef ASTFORMAL_H_
#define ASTFORMAL_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTFormal : public ASTNode {

public:
  virtual ~ASTFormal() {}
};

typedef std::unique_ptr<ASTFormal> ASTFormalPtr;
}
#endif /* ASTFORMAL_H_ */
