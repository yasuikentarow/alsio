/***********************************************************************//**
	@file
***************************************************************************/
#pragma once

namespace alsio::compiler {
/***********************************************************************//**
	@brief 
***************************************************************************/
class Scope {
 private:
  std::string name_;
  std::weak_ptr<Scope> parent_;
  std::vector<ScopePtr> children_;

 public:
  Scope(const std::string& name);
  virtual ~Scope();

  ALSIO_GETTER(Name, name_);
  std::string getPath() const;

  ScopePtr getParent() const;
  void setParent(const ScopePtr& parent);

  ALSIO_GETTER(Children, children_);
  void appendChild(const ScopePtr& child);
  ScopePtr findChild(const std::string& name) const;
};
/***********************************************************************//**
	$Id$
***************************************************************************/
}
