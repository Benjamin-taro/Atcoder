#!/bin/bash
set -e

# PATH を明示（cron対策）
export PATH=/usr/bin:/bin:/usr/sbin:/sbin

commit_repo () {
  REPO_PATH="$1"
  COMMIT_MSG="$2"

  cd "$REPO_PATH" || return 0

  git add .

  # 差分がなければ commit/push しない
  if git diff --cached --quiet; then
    echo "[$REPO_PATH] No changes"
    return 0
  fi

  git commit -m "$COMMIT_MSG"
  git push
}

commit_repo "/Users/iseyuki/atcoder.jp" "Automated commit (atcoder)"
commit_repo "/Users/iseyuki/programming practice/codeforces" "Automated commit (codeforces)"
