#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/AbstractFile.h "
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/CommandPrompt.h"

#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "TouchCatParsingStrategy.h"

#include <sstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    SimpleFileSystem* s = new SimpleFileSystem();
    SimpleFileFactory* sff = new SimpleFileFactory();
    TouchCommand* tc = new TouchCommand(s, sff);
    CatCommand* cc = new CatCommand(s);
    CopyCommand* coc = new CopyCommand(s);
    DisplayCommand* ds = new DisplayCommand(s);
    LSCommand* ls = new LSCommand(s);
    RemoveCommand* rm = new RemoveCommand(s);
    MacroCommand* rn = new MacroCommand(s);
    RenameParsingStrategy* rename = new RenameParsingStrategy();
    rn->setParseStrategy(rename);
    rn->addCommand(coc);
    rn->addCommand(rm);
    MacroCommand* tcat = new MacroCommand(s);
    TouchCatParsingStrategy* tcparse = new TouchCatParsingStrategy();
    tcat->setParseStrategy(tcparse);
    tcat->addCommand(tc);
    tcat->addCommand(cc);
    CommandPrompt* cp = new CommandPrompt();
    cp->setFileSystem(s);
    cp->setFileFactory(sff);
    cp->addCommand("touch", tc);
    cp->addCommand("cat", cc);
    cp->addCommand("cp", coc);
    cp->addCommand("ds", ds);
    cp->addCommand("ls", ls);
    cp->addCommand("rm", rm);
    cp->addCommand("rn", rn);
    cp->addCommand("touch+cat", tcat);
    cp->run();
    return 0;
}