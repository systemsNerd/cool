#ifndef ASTLET_H_
#define ASTLET_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTLet : public ASTNode {

public:
  virtual ~ASTLet() {}
};

typedef std::unique_ptr<ASTLet> ASTLetPtr;
}
#endif /* ASTLET_H_ */
