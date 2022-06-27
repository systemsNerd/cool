#ifndef ASTFEATURE_H_
#define ASTFEATURE_H_

#include "ASTFeature.h"
#include <iostream>
#include <memory>

namespace cool {
class ASTFeature : public ASTNode {

public:
  virtual ~ASTFeature() {}
};

typedef std::unique_ptr<ASTFeature> ASTFeaturePtr;
}
#endif /* ASTFEATURE_H_ */
