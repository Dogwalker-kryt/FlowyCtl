# FlowyCtl
A light weight local Workflow manager and runner for linux

## Description

FlowyCtl is a Linux CLI tool for running and managin .json formated workflows localy

## structure
```sh
src/
  main.cpp
  /cmd_execution
    cmd_exec.h (from Sectr-ctl)
  /flowy_engine
    engine.hpp
    engine.cpp (core utilitys)
  /init
    init.hpp
    init.cpp (functions for initilising flowy in a dir)
  /json_parser
    json.hpp
    json.cpp (small custom parser and structs)
  /list_workflows
    list.hpp
    list.cpp (functions for listing workflows
```

