#ifndef ASTMETHOD_H_
#define ASTMETHOD_H_

#include "ASTFeature.h"
#include <memory>

namespace cool {
class ASTMethod : public ASTFeature {

public:
  virtual ~ASTMethod() {}
  
  private:
    std::string return_type;
    std::string name;
    std::vector<std::unique_ptr<ASTFormal>> formals;
    std::unique_ptr<ASTExpression> body;
};

typedef std::unique_ptr<ASTMethod> ASTMethodPtr;
}
#endif /* ASTMETHOD_H_ */
