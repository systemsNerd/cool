#ifndef ASTATTRIBUTE_H_
#define ASTATTRIBUTE_H_

#include "ASTFeature.h"
#include "ASTExpression.h"
#include <memory>

namespace cool {
class ASTAttribute : public ASTFeature {

public:
  virtual ~ASTAttribute() {}
  ASTAttribute(const std::string &name, const std::string &type, ASTExpressionPtr init) : _name(name),
                                                                                          _type(type), _init(std::move(init)) {}

private:
  std::string _name;
  std::string _type;
  ASTExpressionPtr _init;
};

typedef std::unique_ptr<ASTAttribute> ASTAttributePtr;
}
#endif /* ASTATTRIBUTE_H_ */
