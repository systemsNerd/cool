#ifndef ASTLOCALVARDEF_H_
#define ASTLOCALVARDEF_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTLocalVarDef : public ASTNode {

public:
  virtual ~ASTLocalVarDef() {}
};

typedef std::unique_ptr<ASTLocalVarDef> ASTLocalVarDefPtr;
}
#endif /* ASTLOCALVARDEF_H_ */
