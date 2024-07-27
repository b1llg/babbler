#include "BabblerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
BabblerApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

BabblerApp::BabblerApp(InputParameters parameters) : MooseApp(parameters)
{
  BabblerApp::registerAll(_factory, _action_factory, _syntax);
}

BabblerApp::~BabblerApp() {}

void
BabblerApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<BabblerApp>(f, af, s);
  Registry::registerObjectsTo(f, {"BabblerApp"});
  Registry::registerActionsTo(af, {"BabblerApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
BabblerApp::registerApps()
{
  registerApp(BabblerApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
BabblerApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  BabblerApp::registerAll(f, af, s);
}
extern "C" void
BabblerApp__registerApps()
{
  BabblerApp::registerApps();
}
