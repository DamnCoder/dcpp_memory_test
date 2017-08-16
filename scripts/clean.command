#!/bin/sh

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

rm -r $DIR/build_xcode_test
rm -r $DIR/build_eclipse_test
rm -r $DIR/build_test

exit 0