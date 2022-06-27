#ifndef ASTWHILE_H_
#define ASTWHILE_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTWhile : public ASTNode {

public:
  virtual ~ASTWhile() {}

private:

};

typedef std::unique_ptr<ASTWhile> ASTWhilePtr;
}
#endif /* ASTWHILE_H_ */
