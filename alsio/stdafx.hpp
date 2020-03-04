/***********************************************************************//**
	@file
***************************************************************************/
#include <memory>
#include <string>
#include <vector>
/***********************************************************************//**
	@brief 
***************************************************************************/
#define ALSIO_DECLARE_CLASS(klass)                              \
  class klass;                                                  \
  using klass##Ptr = std::shared_ptr<klass>;                    \
  using Const##klass##Ptr = std::shared_ptr<const klass>;

#define ALSIO_SETTER(name, var) \
  auto& set##name(const auto& value) {          \
    var = value;                                \
    return *this;                               \
  }

#define ALSIO_GETTER(name, var)                 \
  const auto& get##name() const {               \
    return var;                                 \
  }
/***********************************************************************//**
	@brief 
***************************************************************************/
namespace alsio {
namespace compiler {
ALSIO_DECLARE_CLASS(Compiler);
ALSIO_DECLARE_CLASS(Scope);
}
}
/***********************************************************************//**
	$Id$
***************************************************************************/
