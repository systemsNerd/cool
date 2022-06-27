#ifndef ASTVAR_H_
#define ASTVAR_H_

#include "ASTNode.h"
#include <memory>
#include "antlr4-runtime.h"

namespace cool {
class ASTVar : public ASTNode {

public:
  virtual ~ASTVar() {}
  ASTVar(const std::string& name): _name(name) {}

private:
  std::string _name;
};

typedef std::unique_ptr<ASTVar> ASTVarPtr;
}
#endif /* ASTVAR_H_ */
