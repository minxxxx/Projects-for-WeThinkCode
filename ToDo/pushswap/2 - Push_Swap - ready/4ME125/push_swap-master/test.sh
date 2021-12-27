#!/usr/bin/env bash

OK="\033[32m ✔ \033[0m"
ERROR="\033[31m ✖ \033[0m"
WARNING="\033[34m ℹ \033[0m"

function padme {
  S="$1"
  line='                                                                       '
  printf "%s %s" "$S" "${line:${#S}}"
}

function dotest {
  local test=$3
  local test_out="./out/$(basename "${test%.*}").out"
  local test_expected="./test/$(basename "${test%.*}").ex"
  if [ ! -f ${test_expected} ]; then
    test_expected="./test/$(basename "${test%.*}").ex"
    git add test_expected
    ./push_swap $@ &> ${test_expected}
  fi
  rm -f ${test_out}
  ./push_swap $@ &> ${test_out}
  diff ${test_out} ${test_expected}
}

OUT=$(mktemp)
function job {
  echo -en "$(padme "$1: $3") "
  ($3 &> ${OUT}) &
  pid=$!
  wait ${pid}
  local RET=$?
  if [[ $RET != $2 ]]; then
    echo -e "${ERROR} $(cat ${OUT})"
  else
    RET=0
    echo -e "${OK}"
  fi
  return $RET
}

mkdir -p out
job "Test" 1 "./push_swap -v 0 2 6 a"
job "Test" 1 "./push_swap 0 2 6 abc"
job "Test" 1 "./push_swap"
job "Test" 1 "./push_swap abc"
job "Test" 1 "./push_swap -2"
job "Test" 0 "./push_swap -2 -3"
job "Test" 0 "./push_swap -2 -1"
job "Test" 1 "./push_swap -2 -1 -1"
job "Test" 1 "./push_swap 0 1 2 0 -1"
job "Test" 0 "./push_swap 0 1 2 -1"
job "Test" 1 "./push_swap –2147483648 2147483647"
job "Test" 1 "./push_swap 2147483647 –2147483648"
