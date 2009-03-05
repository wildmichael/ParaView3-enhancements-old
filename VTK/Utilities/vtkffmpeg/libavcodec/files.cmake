SET(FFMPEG_avcodec_SRCS
  libavcodec/bitstream.c libavcodec/utils.c libavcodec/allcodecs.c
  libavcodec/mpegvideo.c libavcodec/jrevdct.c libavcodec/jfdctfst.c
  libavcodec/jfdctint.c libavcodec/mjpeg.c libavcodec/resample2.c
  libavcodec/dsputil.c libavcodec/motion_est.c libavcodec/imgconvert.c
  libavcodec/mpeg12.c libavcodec/simple_idct.c libavcodec/ratecontrol.c
  libavcodec/eval.c libavcodec/error_resilience.c libavcodec/fft.c
  libavcodec/mdct.c libavcodec/raw.c libavcodec/faandct.c libavcodec/parser.c
  libavcodec/vp3dsp.c libavcodec/h264idct.c libavcodec/h263.c
  libavcodec/msmpeg4.c libavcodec/h263dec.c libavcodec/opt.c
  libavcodec/bitstream_filter.c libavcodec/asv1.c
  )

IF(HAVE_PTHREADS)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS} libavcodec/pthread.c)
ELSEIF(HAVE_W32THREADS)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS} libavcodec/w32thread.c)
ENDIF(HAVE_PTHREADS)

IF(HAVE_MMX)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/i386/fdct_mmx.c libavcodec/i386/cputest.c
    libavcodec/i386/dsputil_mmx.c libavcodec/i386/mpegvideo_mmx.c
    libavcodec/i386/motion_est_mmx.c libavcodec/i386/simple_idct_mmx.c
    libavcodec/i386/fft_sse.c libavcodec/i386/vp3dsp_mmx.c
    libavcodec/i386/vp3dsp_sse2.c libavcodec/i386/fft_3dn.c
    libavcodec/i386/fft_3dn2.c
    )
    IF(HAVE_BUILTIN_VECTOR)
      SET_SOURCE_FILES_PROPERTIES(libavcodec/i386/fft_sse.c PROPERTIES
        COMPILE_FLAGS -msse
        )
    ENDIF(HAVE_BUILTIN_VECTOR)
    IF(HAVE_BUILTIN_3DNOW)
      SET_SOURCE_FILES_PROPERTIES(libavcodec/i386/fft_3dn.c PROPERTIES
        COMPILE_FLAGS -m3dnow
        )
    ENDIF(HAVE_BUILTIN_3DNOW)

    IF(ARCH_X86)
      SET_SOURCE_FILES_PROPERTIES(libavcodec/i386/fft_3dn2.c PROPERTIES
        COMPILE_FLAGS -march=athlon
        )
    ENDIF(ARCH_X86)
    IF(ARCH_X86_64)
      SET_SOURCE_FILES_PROPERTIES(libavcodec/i386/fft_3dn2.c PROPERTIES
        COMPILE_FLAGS -march=k8
        )
    ENDIF(ARCH_X86_64)
ENDIF(HAVE_MMX)

# ARM files
IF(ARCH_ARMV4L)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/armv4l/jrevdct_arm.S libavcodec/armv4l/simple_idct_arm.S
    libavcodec/armv4l/dsputil_arm_s.S libavcodec/armv4l/dsputil_arm.c
    libavcodec/armv4l/mpegvideo_arm.c
    )
  IF(HAVE_IWMMXT)
    SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
      libavcodec/armv4l/dsputil_iwmmxt.c libavcodec/armv4l/mpegvideo_iwmmxt.c
      )
  ENDIF(HAVE_IWMMXT)
  IF(HAVE_ARMV5TE)
    SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
      libavcodec/armv4l/simple_idct_armv5te.S
      )
  ENDIF(HAVE_ARMV5TE)
ENDIF(ARCH_ARMV4L)

# sun sparc files
IF(ARCH_SPARC)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/sparc/dsputil_vis.c
    )
  SET_SOURCE_FILES_PROPERTIES(libavcodec/sparc/dsputil_vis.c PROPERTIES
    COMPILE_FLAGS -mcpu=ultrasparc -mtune=ultrasparc
    )
ENDIF(ARCH_SPARC)

# alpha files
IF(ARCH_ALPHA)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/alpha/dsputil_alpha.c libavcodec/alpha/mpegvideo_alpha.c
    libavcodec/alpha/simple_idct_alpha.c libavcodec/alpha/motion_est_alpha.c
    alpha/dsputil_alpha_asm.S alpha/motion_est_mvi_asm.S
    )
ENDIF(ARCH_ALPHA)

# powerpc files
IF(ARCH_POWERPC OR APPLE)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/ppc/dsputil_ppc.c libavcodec/ppc/mpegvideo_ppc.c
    )
ENDIF(ARCH_POWERPC OR APPLE)

# mips mmi files
IF(HAVE_MMI)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/ps2/dsputil_mmi.c libavcodec/ps2/idct_mmi.c
    libavcodec/ps2/mpegvideo_mmi.c
    )
ENDIF(HAVE_MMI)

# sh4 files
IF(ARCH_SH4)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/sh4/idct_sh4.c libavcodec/sh4/dsputil_sh4.c
    libavcodec/sh4/dsputil_align.c
    )
ENDIF(ARCH_SH4)

# altivec files
IF(HAVE_ALTIVEC OR APPLE)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/ppc/dsputil_altivec.c libavcodec/ppc/mpegvideo_altivec.c
    libavcodec/ppc/idct_altivec.c libavcodec/ppc/fft_altivec.c
    libavcodec/ppc/gmc_altivec.c libavcodec/ppc/fdct_altivec.c
    libavcodec/ppc/h264_altivec.c libavcodec/ppc/vc1dsp_altivec.c
    libavcodec/ppc/float_altivec.c
    )
ENDIF(HAVE_ALTIVEC OR APPLE)

IF(HAVE_BFIN)
  SET(FFMPEG_avcodec_SRCS ${FFMPEG_avcodec_SRCS}
    libavcodec/bfin/dsputil_bfin.c
    )
ENDIF(HAVE_BFIN)
