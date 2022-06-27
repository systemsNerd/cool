#ifndef ASTCLASS_H_
#define ASTCLASS_H_

#include "ASTNode.h"
#include "ASTFeature.h"
#include <memory>
#include <vector>

namespace cool {
class ASTClass : public ASTNode {

public:
  virtual ~ASTClass() {}
  void addFeature(std::unique_ptr<ASTFeature> F) {
    features.push_back(std::move(F));
  }


private:
  std::string name;
  std::string parent;
  std::vector<std::unique_ptr<ASTFeature>> features;
};

typedef std::unique_ptr<ASTClass> ASTClassPtr;
}
#endif /* ASTCLASS_H_ */
