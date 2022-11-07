#include "buf.h"
	git_str *buf;
	git_str *out,
	git_str *out,
	git_str *out,
	GIT_ASSERT_ARG(patch);
	git_str *out = pi->buf;
	git_str_clear(out);
	git_str_puts(out, delta->new_file.path);
	git_str_putc(out, '\n');
	if (git_str_oom(out))
	pi->line.content     = git_str_cstr(out);
	pi->line.content_len = git_str_len(out);
	git_str *out = pi->buf;
	git_str_clear(out);
		git_str_printf(out, "%c\t%s%c %s%c\n", code,
		git_str_printf(out, "%c\t%s%c %s%c\n", code,
		git_str_printf(out, "%c\t%s%c\n", code, delta->old_file.path, old_suffix);
		git_str_printf(out, "%c\t%s\n", code, delta->old_file.path);
	if (git_str_oom(out))
	pi->line.content     = git_str_cstr(out);
	pi->line.content_len = git_str_len(out);
	git_str *out = pi->buf;
	git_str_clear(out);
	git_str_printf(
		git_str_printf(out, "%03u", delta->similarity);
		git_str_printf(
		git_str_printf(
	if (git_str_oom(out))
	pi->line.content     = git_str_cstr(out);
	pi->line.content_len = git_str_len(out);
	git_str *out, const git_diff_delta *delta)
	git_str_printf(out, "old mode %o\n", delta->old_file.mode);
	git_str_printf(out, "new mode %o\n", delta->new_file.mode);
	return git_str_oom(out) ? -1 : 0;
	git_str *out, const git_diff_delta *delta, int id_strlen,
			git_str_printf(out, "index %s..%s %o\n",
			git_str_printf(out, "new file mode %o\n", delta->new_file.mode);
			git_str_printf(out, "deleted file mode %o\n", delta->old_file.mode);
			git_str_printf(out, "index %s..%s\n", start_oid, end_oid);
	return git_str_oom(out) ? -1 : 0;
	git_str *out, const char *prefix, const char *filename)
	if (!filename) {
		/* don't prefix "/dev/null" */
 		return git_str_puts(out, "/dev/null");
	}

	if (git_str_joinpath(out, prefix, filename) < 0)
	return git_str_quote(out);
	git_str *out,
	return git_str_printf(out, template, oldpath, newpath);
	git_str *out,
	git_str old_path = GIT_STR_INIT, new_path = GIT_STR_INIT;
	if ((error = git_str_puts(&old_path, delta->old_file.path)) < 0 ||
	    (error = git_str_puts(&new_path, delta->new_file.path)) < 0 ||
	    (error = git_str_quote(&old_path)) < 0 ||
	    (error = git_str_quote(&new_path)) < 0)
	git_str_printf(out,
	if (git_str_oom(out))
	git_str_dispose(&old_path);
	git_str_dispose(&new_path);
	git_str *out,
	git_str old_path = GIT_STR_INIT, new_path = GIT_STR_INIT;
	git_str_clear(out);
	git_str_printf(out, "diff --git %s %s\n",
	if (git_str_oom(out))
	git_str_dispose(&old_path);
	git_str_dispose(&new_path);
	git_str_printf(pi->buf, "%s %" PRIuZ "\n", typename, inflatedlen);
			git_str_putc(pi->buf, (char)chunk_len + 'A' - 1);
			git_str_putc(pi->buf, (char)chunk_len - 26 + 'a' - 1);
		git_str_encode_base85(pi->buf, scan, chunk_len);
		git_str_putc(pi->buf, '\n');
		if (git_str_oom(pi->buf))
	git_str_putc(pi->buf, '\n');
	if (git_str_oom(pi->buf))
	git_str old_path = GIT_STR_INIT, new_path = GIT_STR_INIT;
	git_str_dispose(&old_path);
	git_str_dispose(&new_path);
	git_str_printf(pi->buf, "GIT binary patch\n");
			git_str_truncate(pi->buf, pre_binary_size);
	pi->line.content     = git_str_cstr(pi->buf);
	pi->line.content_len = git_str_len(pi->buf);
	git_str_clear(pi->buf);
	pi->line.content = git_str_cstr(pi->buf);
	pi->line.content_len = git_str_len(pi->buf);
	git_str buf = GIT_STR_INIT;
	git_str_dispose(&buf);
	git_str *output = payload;
		git_str_putc(output, line->origin);
	return git_str_put(output, line->content, line->content_len);
/* print a git_diff to a git_str */
	git_str str = GIT_STR_INIT;
	int error;

	GIT_ASSERT_ARG(out);
	GIT_ASSERT_ARG(diff);

	if ((error = git_buf_tostr(&str, out)) < 0 ||
	    (error = git_diff_print(diff, format, git_diff_print_callback__to_buf, &str)) < 0)
		goto done;

	error = git_buf_fromstr(out, &str);

done:
	git_str_dispose(&str);
	return error;
	git_str temp = GIT_STR_INIT;
	GIT_ASSERT_ARG(patch);
	GIT_ASSERT_ARG(print_cb);
	git_str_dispose(&temp);
/* print a git_patch to a git_str */
	GIT_BUF_WRAP_PRIVATE(out, git_patch__to_buf, patch);
}

int git_patch__to_buf(git_str *out, git_patch *patch)
{
	GIT_ASSERT_ARG(out);
	GIT_ASSERT_ARG(patch);
