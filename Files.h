if (ext == ".mpl") run_mplisde(file);
if (ext == ".bf") run_brainfuck(file);
if (ext == ".bin") run_binary(file);
if (ext == ".elf") load_elf(file);
if (ext == ".js") load_javascript(file);
if (ext == ".java") load_java(file);
if (ext == ".json") load_json(file);
if (ext == ".*") load_all_language(file);
