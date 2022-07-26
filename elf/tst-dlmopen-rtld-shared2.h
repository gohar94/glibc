static dlmopen_test_spec dltest[] =
  {
   {
    .name = "dlmopen-shared:0:none--ns0",
    .desc = "dlmopen as dlopen with RTLD_SHARED",
    .args.dso_path = DSO_NORMAL,
    .args.ns = LM_ID_BASE,
    .args.flags  = RTLD_SHARED,
    .loaded = { [0] = DSO|NEW },
    .handle_ns = LM_ID_BASE,
    .handle_type = DSO,
   },
   {
    .name = "dlmopen-shared:X:ns0--ns0-nsXp",
    .desc = "dlmopen into a new namespace with the target already in the base NS",
    .args.dso_path = DSO_NORMAL,
    .args.ns = LM_ID_NEWLM,
    .args.flags = RTLD_SHARED,
    .handle_ns = EXPECTED_NS,
    .handle_type = PROXY,
    .preloaded = { [0] = DSO },
    .loaded = { [0] = DSO, [EXPECTED_NS] = PROXY|NEW }
   },
   {
    .name = "dlmopen:0:ns0-nsXp--ns0-nsXp",
    .desc = "dlmopen into base NS while proxy already in nsX",
    .args.dso_path = DSO_NORMAL,
    .args.ns = LM_ID_BASE,
    .handle_ns = 0,
    .handle_type = DSO,
    .preloaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
    .loaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
   },
   {
    .name = "dlmopen-shared:0:ns0-nsXp--ns0-nsXp",
    .desc = "dlmopen with RTLD_SHARED into base NS while proxy already in nsX",
    .args.dso_path = DSO_NORMAL,
    .args.ns = LM_ID_BASE,
    .args.flags = RTLD_SHARED,
    .handle_ns = 0,
    .handle_type = DSO,
    .preloaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
    .loaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
   },
   {
    .name = "dlmopen:X:ns0-nsXp--ns0-nsXp",
    .desc = "dlmopen into NS X while proxy already in nsX",
    .args.dso_path = DSO_NORMAL,
    .args.ns = EXPECTED_NS,
    .handle_ns = EXPECTED_NS,
    .handle_type = PROXY,
    .preloaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
    .loaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
   },
   {
    .name = "dlmopen-shared:X:ns0-nsXp--ns0-nsXp",
    .desc = "dlmopen with RTLD_SHARED into NS X while proxy already in nsX",
    .args.dso_path = DSO_NORMAL,
    .args.ns = EXPECTED_NS,
    .args.flags = RTLD_SHARED,
    .handle_ns = EXPECTED_NS,
    .handle_type = PROXY,
    .preloaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
    .loaded = { [0] = DSO, [EXPECTED_NS] = PROXY },
   },
  };
