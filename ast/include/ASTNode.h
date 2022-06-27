#ifndef ASTNODE_H_
#define ASTNODE_H_

#include <iostream>
#include <string>
#include <memory>

namespace cool {
class ASTNode {

public:
  ASTNode() {}
  virtual ~ASTNode() {}
};

typedef std::unique_ptr<ASTNode> ASTNodePtr;
}

#endif /* ASTNODE_H_ */
