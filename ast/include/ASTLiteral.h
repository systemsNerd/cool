#ifndef ASTLITERAL_H_
#define ASTLITERAL_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTLiteral : public ASTNode {

public:
  virtual ~ASTLiteral() {}
  ASTLiteral() {}
  explicit ASTLiteral(const std::string& l): _l(l) {}


private:
  std::string _l;

};

typedef std::unique_ptr<ASTLiteral> ASTLiteralPtr;
}
#endif /* ASTLITERAL_H_ */
