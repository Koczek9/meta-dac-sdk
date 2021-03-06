SUMMARY = "Example wayland egl test application"

LICENSE = "Unlicense"
LIC_FILES_CHKSUM = "file://LICENSE;md5=0d2f730e01d19e8f457a65e092b60770"

DEPENDS =  "virtual/egl virtual/libgles2 libepoxy libxkbcommon"

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

S = "${WORKDIR}/git/wayland-egl-test"

SRC_URI = " \
    git://github.com/stagingrdkm/dac-examples-src.git;protocol=http;branch=master;rev=927725b156d7be6ceb98301422a2cb5650ae8cd6 \
"

inherit pkgconfig

TEST_NAME         = "wayland-egl-test"
TEST_NAME_EPOXY   = "wayland-egl-test-epoxy"

INPUT_NAME         = "wayland-egl-test-input"
INPUT_NAME_EPOXY   = "wayland-egl-test-input-epoxy"

TARGET_CFLAGS     += " -O3 -ggdb3"

TARGET_CC_ARCH    += "${LDFLAGS}"

do_compile () {
  cd ${S}
  ${CC} ${TARGET_CFLAGS}              -o ${TEST_NAME}       wayland-egl.c    $(pkg-config --cflags --libs       wayland-client wayland-egl glesv2 egl)
  ${CC} ${TARGET_CFLAGS} -DHAVE_EPOXY -o ${TEST_NAME_EPOXY} wayland-egl.c    $(pkg-config --cflags --libs epoxy wayland-client wayland-egl)

  ${CC} ${TARGET_CFLAGS}              -o ${INPUT_NAME}       wayland-input.c $(pkg-config --cflags --libs       wayland-client wayland-egl glesv2 egl xkbcommon)
  ${CC} ${TARGET_CFLAGS} -DHAVE_EPOXY -o ${INPUT_NAME_EPOXY} wayland-input.c $(pkg-config --cflags --libs epoxy wayland-client wayland-egl            xkbcommon)
}

do_install() {
  install -p -m 0755 -D ${S}/${TEST_NAME}         ${D}${bindir}/${TEST_NAME}
  install -p -m 0755 -D ${S}/${TEST_NAME_EPOXY}   ${D}${bindir}/${TEST_NAME_EPOXY}
  install -p -m 0755 -D ${S}/${INPUT_NAME}        ${D}${bindir}/${INPUT_NAME}
  install -p -m 0755 -D ${S}/${INPUT_NAME_EPOXY}  ${D}${bindir}/${INPUT_NAME_EPOXY}
}

FILES_${PN} += "${bindir}/*"

