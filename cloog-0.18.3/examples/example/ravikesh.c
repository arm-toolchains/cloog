/* example-isl.c */
#include <cloog/cloog.h>
#include <cloog/isl/cloog.h>

/* Input problem */
int nb_parameters = 1;
char *str_context    = "[N] -> {[] : N > 0}";
char *str_domain     = "[N] -> {[i, j] : 0 <= i < N and 0 <= j < N}";
char *str_scattering = "[N] -> {[i, j] -> [i + j, q, j] : exists r : j = 2*q + r and 0 <= r < 2}";

int main() {
  isl_ctx *ctx;
  isl_set *set_context, *set;
  isl_map *map;
  CloogDomain *context, *domain;
  CloogScattering *scattering;
  CloogUnionDomain *domains;
  CloogInput *input;
  CloogState *state;
  CloogOptions *options;
  struct clast_stmt *root;

  /* Build isl structures for context, sets and mapping */
  ctx = isl_ctx_alloc();
  set_context = isl_set_read_from_str(ctx, str_context);
  set = isl_set_read_from_str(ctx, str_domain);
  map = isl_map_read_from_str(ctx, str_scattering);

  /* Translate them to CLooG context, domains and scattering */
  context = cloog_domain_from_isl_set(set_context);
  domain = cloog_domain_from_isl_set(set);
  scattering = cloog_scattering_from_isl_map(map);

  /* Prepare the list of domains to scan */
  domains = cloog_union_domain_alloc(nb_parameters);
  cloog_union_domain_add_domain(domains, "S1", domain, scattering, NULL);

  /* Build the input, generate the AST of the scanning code and print it */
  input = cloog_input_alloc(context, domains);
  state = cloog_isl_state_malloc(ctx);
  options = cloog_options_malloc(state);
  root = cloog_clast_create_from_input(input, options);
  clast_pprint(stdout, root, 0, options);

  /* Recycle allocated memory */
  isl_ctx_free(ctx);
  cloog_clast_free(root);
  cloog_options_free(options);
  cloog_state_free(state);
}
