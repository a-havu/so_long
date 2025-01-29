
if (NOT EXISTS "/Users/aino/Desktop/HIVE/P_so_long/MLX42/build/_deps/glfw-build/install_manifest.txt")
  message(FATAL_ERROR "Cannot find install manifest: \"/Users/aino/Desktop/HIVE/P_so_long/MLX42/build/_deps/glfw-build/install_manifest.txt\"")
endif()

file(READ "/Users/aino/Desktop/HIVE/P_so_long/MLX42/build/_deps/glfw-build/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach (file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    exec_program("/private/var/folders/8c/b310r2l13xl19kv4qh7bq7kc0000gn/T/AppTranslocation/52F61E46-E698-4EB1-BB09-F972CAF8BF5F/d/CMake.app/Contents/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  elseif (IS_SYMLINK "$ENV{DESTDIR}${file}")
    EXEC_PROGRAM("/private/var/folders/8c/b310r2l13xl19kv4qh7bq7kc0000gn/T/AppTranslocation/52F61E46-E698-4EB1-BB09-F972CAF8BF5F/d/CMake.app/Contents/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing symlink \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()

