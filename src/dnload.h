#ifndef DNLOAD_H
#define DNLOAD_H

/** \file
 * \brief Dynamic loader header stub.
 *
 * This file was automatically generated by 'dnload.py'.
 */

#if defined(WIN32)
/** \cond */
#define _USE_MATH_DEFINES
#define NOMINMAX
/** \endcond */
#else
/** \cond */
#define GL_GLEXT_PROTOTYPES
/** \endcond */
#endif

#if defined(__cplusplus)
#include <cmath>
#include <cstdlib>
#else
#include <math.h>
#include <stdlib.h>
#endif

#if defined(DNLOAD_VIDEOCORE)
#include "bcm_host.h"
#include "EGL/egl.h"
#endif

#if defined(USE_LD)
#if defined(WIN32)
#include "windows.h"
#include "GL/glew.h"
#include "GL/glu.h"
#include "SDL.h"
#elif defined(__APPLE__)
#include "GL/glew.h"
#include <OpenGL/glu.h>
#include "SDL.h"
#else
#if defined(DNLOAD_GLESV2)
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#else
#include "GL/glew.h"
#include "GL/glu.h"
#endif
#include "SDL.h"
#endif
#include "bsd_rand.h"
#else
#if defined(__APPLE__)
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
#include <OpenGL/glu.h>
#include "SDL.h"
#else
#if defined(DNLOAD_GLESV2)
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#else
#include "GL/gl.h"
#include "GL/glext.h"
#include "GL/glu.h"
#endif
#include "SDL.h"
#endif
#endif

#if defined(SDL_INIT_EVERYTHING) && defined(__APPLE__) 
#define DNLOAD_MAIN SDL_main
#else
#define DNLOAD_MAIN main
#endif

/** Macro stringification helper (adds indirection). */
#define DNLOAD_MACRO_STR_HELPER(op) #op
/** Macro stringification. */
#define DNLOAD_MACRO_STR(op) DNLOAD_MACRO_STR_HELPER(op)

#if defined(DNLOAD_GLESV2)
/** Apientry definition (OpenGL ES 2.0). */
#define DNLOAD_APIENTRY GL_APIENTRY
#else
/** Apientry definition (OpenGL). */
#define DNLOAD_APIENTRY GLAPIENTRY
#endif

#if (defined(_LP64) && _LP64) || (defined(__LP64__) && __LP64__)
/** Size of pointer in bytes (64-bit). */
#define DNLOAD_POINTER_SIZE 8
#else
/** Size of pointer in bytes (32-bit). */
#define DNLOAD_POINTER_SIZE 4
#endif

#if !defined(USE_LD)
/** Error string for when assembler exit procedure is not available. */
#define DNLOAD_ASM_EXIT_ERROR "no assembler exit procedure defined for current operating system or architecture"
/** Perform exit syscall in assembler. */
static void asm_exit(void)
{
#if !defined(DNLOAD_NO_DEBUGGER_TRAP) && (defined(__x86_64__) || defined(__i386__))
  asm("int $0x3" : /* no output */ : /* no input */ : /* no clobber */);
#elif defined(__x86_64__)
#if defined(__FreeBSD__)
  asm_exit() asm("syscall" : /* no output */ : "a"(1) : /* no clobber */);
#elif defined(__linux__)
  asm_exit() asm("syscall" : /* no output */ : "a"(60) : /* no clobber */);
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
#elif defined(__i386__)
#if defined(__FreeBSD__) || defined(__linux__)
  asm("int $0x80" : /* no output */ : "a"(1) : /* no clobber */);
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
#elif defined(__arm__)
#if defined(__linux__)
  register int r7 asm("r7") = 1;
  asm("swi #0" : /* no output */ : "r"(r7) : /* no clobber */);
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
#else
#pragma message DNLOAD_MACRO_STR(DNLOAD_ASM_EXIT_ERROR)
#error
#endif
}
#endif

#if defined(USE_LD)
/** \cond */
#define dnload_bcm_host_init bcm_host_init
#define dnload_eglInitialize eglInitialize
#define dnload_glClear glClear
#define dnload_eglCreateWindowSurface eglCreateWindowSurface
#define dnload_eglSwapBuffers eglSwapBuffers
#define dnload_vc_dispmanx_update_submit_sync vc_dispmanx_update_submit_sync
#define dnload_vc_dispmanx_element_add vc_dispmanx_element_add
#define dnload_vc_dispmanx_display_open vc_dispmanx_display_open
#define dnload_SDL_Init SDL_Init
#define dnload_SDL_Quit SDL_Quit
#define dnload_puts puts
#define dnload_graphics_get_display_size graphics_get_display_size
#define dnload_eglGetDisplay eglGetDisplay
#define dnload_bcm_host_deinit bcm_host_deinit
#define dnload_eglTerminate eglTerminate
#define dnload_vc_dispmanx_update_start vc_dispmanx_update_start
#define dnload_eglCreateContext eglCreateContext
#define dnload_eglChooseConfig eglChooseConfig
#define dnload_eglMakeCurrent eglMakeCurrent
/** \endcond */
#else
/** \cond */
#define dnload_bcm_host_init g_symbol_table.bcm_host_init
#define dnload_eglInitialize g_symbol_table.eglInitialize
#define dnload_glClear g_symbol_table.glClear
#define dnload_eglCreateWindowSurface g_symbol_table.eglCreateWindowSurface
#define dnload_eglSwapBuffers g_symbol_table.eglSwapBuffers
#define dnload_vc_dispmanx_update_submit_sync g_symbol_table.vc_dispmanx_update_submit_sync
#define dnload_vc_dispmanx_element_add g_symbol_table.vc_dispmanx_element_add
#define dnload_vc_dispmanx_display_open g_symbol_table.vc_dispmanx_display_open
#define dnload_SDL_Init g_symbol_table.SDL_Init
#define dnload_SDL_Quit g_symbol_table.SDL_Quit
#define dnload_puts g_symbol_table.puts
#define dnload_graphics_get_display_size g_symbol_table.graphics_get_display_size
#define dnload_eglGetDisplay g_symbol_table.eglGetDisplay
#define dnload_bcm_host_deinit g_symbol_table.bcm_host_deinit
#define dnload_eglTerminate g_symbol_table.eglTerminate
#define dnload_vc_dispmanx_update_start g_symbol_table.vc_dispmanx_update_start
#define dnload_eglCreateContext g_symbol_table.eglCreateContext
#define dnload_eglChooseConfig g_symbol_table.eglChooseConfig
#define dnload_eglMakeCurrent g_symbol_table.eglMakeCurrent
/** \endcond */
/** \brief Symbol table structure.
 *
 * Contains all the symbols required for dynamic linking.
 */
static struct SymbolTableStruct
{
  void (*bcm_host_init)(void);
  EGLBoolean (*eglInitialize)(EGLDisplay, EGLint*, EGLint*);
  void (DNLOAD_APIENTRY *glClear)(GLbitfield);
  EGLSurface (*eglCreateWindowSurface)(EGLDisplay, EGLConfig, EGLNativeWindowType, EGLint const*);
  EGLBoolean (*eglSwapBuffers)(EGLDisplay, EGLSurface);
  int (*vc_dispmanx_update_submit_sync)(DISPMANX_UPDATE_HANDLE_T);
  DISPMANX_ELEMENT_HANDLE_T (*vc_dispmanx_element_add)(DISPMANX_UPDATE_HANDLE_T, DISPMANX_DISPLAY_HANDLE_T, int32_t, const VC_RECT_T*, DISPMANX_RESOURCE_HANDLE_T, const VC_RECT_T*, DISPMANX_PROTECTION_T, VC_DISPMANX_ALPHA_T*, DISPMANX_CLAMP_T*, DISPMANX_TRANSFORM_T);
  DISPMANX_DISPLAY_HANDLE_T (*vc_dispmanx_display_open)(uint32_t);
  int (*SDL_Init)(Uint32);
  void (*SDL_Quit)(void);
  int (*puts)(const char*);
  int32_t (*graphics_get_display_size)(const uint16_t, uint32_t*, uint32_t*);
  EGLDisplay (*eglGetDisplay)(NativeDisplayType);
  void (*bcm_host_deinit)(void);
  EGLBoolean (*eglTerminate)(EGLDisplay);
  DISPMANX_UPDATE_HANDLE_T (*vc_dispmanx_update_start)(int32_t);
  EGLContext (*eglCreateContext)(EGLDisplay, EGLConfig, EGLContext, EGLint const*);
  EGLBoolean (*eglChooseConfig)(EGLDisplay, EGLint const*, EGLConfig*, EGLint, EGLint*);
  EGLBoolean (*eglMakeCurrent)(EGLDisplay, EGLSurface, EGLSurface, EGLContext);
} g_symbol_table =
{
  (void (*)(void))0x152389b4,
  (EGLBoolean (*)(EGLDisplay, EGLint*, EGLint*))0x1e979dfa,
  (void (DNLOAD_APIENTRY *)(GLbitfield))0x1fd92088,
  (EGLSurface (*)(EGLDisplay, EGLConfig, EGLNativeWindowType, EGLint const*))0x28e70577,
  (EGLBoolean (*)(EGLDisplay, EGLSurface))0x2bbe59d6,
  (int (*)(DISPMANX_UPDATE_HANDLE_T))0x318e9a39,
  (DISPMANX_ELEMENT_HANDLE_T (*)(DISPMANX_UPDATE_HANDLE_T, DISPMANX_DISPLAY_HANDLE_T, int32_t, const VC_RECT_T*, DISPMANX_RESOURCE_HANDLE_T, const VC_RECT_T*, DISPMANX_PROTECTION_T, VC_DISPMANX_ALPHA_T*, DISPMANX_CLAMP_T*, DISPMANX_TRANSFORM_T))0x5589e071,
  (DISPMANX_DISPLAY_HANDLE_T (*)(uint32_t))0x6df9e514,
  (int (*)(Uint32))0x70d6574,
  (void (*)(void))0x7eb657f3,
  (int (*)(const char*))0x950c8684,
  (int32_t (*)(const uint16_t, uint32_t*, uint32_t*))0x97bb35db,
  (EGLDisplay (*)(NativeDisplayType))0xabd36ff6,
  (void (*)(void))0xadd96fb5,
  (EGLBoolean (*)(EGLDisplay))0xb87f4317,
  (DISPMANX_UPDATE_HANDLE_T (*)(int32_t))0xb8dfc099,
  (EGLContext (*)(EGLDisplay, EGLConfig, EGLContext, EGLint const*))0xd95202a9,
  (EGLBoolean (*)(EGLDisplay, EGLint const*, EGLConfig*, EGLint, EGLint*))0xf4628a23,
  (EGLBoolean (*)(EGLDisplay, EGLSurface, EGLSurface, EGLContext))0xf780cac1,
};
#endif

#if defined(USE_LD)
/** \cond */
#define dnload()
/** \endcond */
#else
#include <stdint.h>
/** \brief SDBM hash function.
 *
 * \param op String to hash.
 * \return Full hash.
 */
static uint32_t sdbm_hash(const uint8_t *op)
{
  uint32_t ret = 0;
  for(;;)
  {
    uint32_t cc = *op++;
    if(!cc)
    {
      return ret;
    }
    ret = ret * 65599 + cc;
  }
}
#if defined(__FreeBSD__)
#include <sys/link_elf.h>
#elif defined(__linux__)
#include <link.h>
#else
#error "no elf header location known for current platform"
#endif
#if (8 == DNLOAD_POINTER_SIZE)
/** Elf header type. */
typedef Elf64_Ehdr dnload_elf_ehdr_t;
/** Elf program header type. */
typedef Elf64_Phdr dnload_elf_phdr_t;
/** Elf dynamic structure type. */
typedef Elf64_Dyn dnload_elf_dyn_t;
/** Elf symbol table entry type. */
typedef Elf64_Sym dnload_elf_sym_t;
/** Elf dynamic structure tag type. */
typedef Elf64_Sxword dnload_elf_tag_t;
#else
/** Elf header type. */
typedef Elf32_Ehdr dnload_elf_ehdr_t;
/** Elf program header type. */
typedef Elf32_Phdr dnload_elf_phdr_t;
/** Elf dynamic structure type. */
typedef Elf32_Dyn dnload_elf_dyn_t;
/** Elf symbol table entry type. */
typedef Elf32_Sym dnload_elf_sym_t;
/** Elf dynamic structure tag type. */
typedef Elf32_Sword dnload_elf_tag_t;
#endif
/** \brief ELF base address. */
#define ELF_BASE_ADDRESS 0x10000
/** \brief Get dynamic section element by tag.
 *
 * \param dyn Dynamic section.
 * \param tag Tag to look for.
 * \return Pointer to dynamic element.
 */
static const dnload_elf_dyn_t* elf_get_dynamic_element_by_tag(const void *dyn, dnload_elf_tag_t tag)
{
  const dnload_elf_dyn_t *dynamic = (const dnload_elf_dyn_t*)dyn;
  do {
    ++dynamic; // First entry in PT_DYNAMIC is probably nothing important.
#if defined(__linux__) && defined(DNLOAD_SAFE_SYMTAB_HANDLING)
    if(0 == dynamic->d_tag)
    {
      return NULL;
    }
#endif
  } while(dynamic->d_tag != tag);
  return dynamic;
}
#if defined(DNLOAD_NO_FIXED_R_DEBUG_ADDRESS) || defined(DNLOAD_SAFE_SYMTAB_HANDLING)
/** \brief Get the address associated with given tag in a dynamic section.
 *
 * \param dyn Dynamic section.
 * \param tag Tag to look for.
 * \return Address matching given tag.
 */
static const void* elf_get_dynamic_address_by_tag(const void *dyn, dnload_elf_tag_t tag)
{
  const dnload_elf_dyn_t *dynamic = elf_get_dynamic_element_by_tag(dyn, tag);
#if defined(__linux__) && defined(DNLOAD_SAFE_SYMTAB_HANDLING)
  if(NULL == dynamic)
  {
    return NULL;
  }
#endif
  return (const void*)dynamic->d_un.d_ptr;
}
#endif
#if !defined(DNLOAD_NO_FIXED_R_DEBUG_ADDRESS)
/** Link map address, fixed location in ELF headers. */
extern const struct r_debug *dynamic_r_debug;
#endif
/** \brief Get the program link map.
 *
 * \return Link map struct.
 */
static const struct link_map* elf_get_link_map()
{
#if defined(DNLOAD_NO_FIXED_R_DEBUG_ADDRESS)
  // ELF header is in a fixed location in memory.
  // First program header is located directly afterwards.
  const dnload_elf_ehdr_t *ehdr = (const dnload_elf_ehdr_t*)ELF_BASE_ADDRESS;
  const dnload_elf_phdr_t *phdr = (const dnload_elf_phdr_t*)((size_t)ehdr + (size_t)ehdr->e_phoff);
  do {
    ++phdr; // Dynamic header is probably never first in PHDR list.
  } while(phdr->p_type != PT_DYNAMIC);
  // Find the debug entry in the dynamic header array.
  {
    const struct r_debug *debug = (const struct r_debug*)elf_get_dynamic_address_by_tag((const void*)phdr->p_vaddr, DT_DEBUG);
    return debug->r_map;
  }
#else
  return dynamic_r_debug->r_map;
#endif
}
/** \brief Return pointer from link map address.
 *
 * \param lmap Link map.
 * \param ptr Pointer in this link map.
 */
static const void* elf_transform_dynamic_address(const struct link_map *lmap, const void *ptr)
{
#if defined(__linux__)
  // Addresses may also be absolute.
  if(ptr >= (void*)(size_t)lmap->l_addr)
  {
    return ptr;
  }
#endif
  return (uint8_t*)ptr + (size_t)lmap->l_addr;
}
#if defined(DNLOAD_SAFE_SYMTAB_HANDLING)
/** \brief Get address of one dynamic section corresponding to given library.
 *
 * \param lmap Link map.
 * \param tag Tag to look for.
 * \return Pointer to given section or NULL.
 */
static const void* elf_get_library_dynamic_section(const struct link_map *lmap, dnload_elf_tag_t tag)
{
  return elf_transform_dynamic_address(lmap, elf_get_dynamic_address_by_tag(lmap->l_ld, tag));
}
#endif
/** \brief Find a symbol in any of the link maps.
 *
 * Should a symbol with name matching the given hash not be present, this function will happily continue until
 * we crash. Size-minimal code has no room for error checking.
 *
 * \param hash Hash of the function name string.
 * \return Symbol found.
 */
static void* dnload_find_symbol(uint32_t hash)
{
  const struct link_map* lmap = elf_get_link_map();
#if defined(__linux__) && (8 == DNLOAD_POINTER_SIZE)
  // On 64-bit Linux, the second entry is not usable.
  lmap = lmap->l_next;
#endif
  for(;;)
  {
    // First entry is this object itself, safe to advance first.
    lmap = lmap->l_next;
    {
#if defined(DNLOAD_SAFE_SYMTAB_HANDLING)
      // Find symbol from link map. We need the string table and a corresponding symbol table.
      const char* strtab = (const char*)elf_get_library_dynamic_section(lmap, DT_STRTAB);
      const dnload_elf_sym_t *symtab = (const dnload_elf_sym_t*)elf_get_library_dynamic_section(lmap, DT_SYMTAB);
      const uint32_t* hashtable = (const uint32_t*)elf_get_library_dynamic_section(lmap, DT_HASH);
      unsigned dynsymcount;
      unsigned ii;
#if defined(__linux__)
      if(NULL == hashtable)
      {
        hashtable = (const uint32_t*)elf_get_library_dynamic_section(lmap, DT_GNU_HASH);
        // DT_GNU_HASH symbol counter borrows from FreeBSD rtld-elf implementation.
        dynsymcount = 0;
        {
          unsigned bucket_count = hashtable[0];
          const uint32_t* buckets = hashtable + 4 + ((sizeof(void*) / 4) * hashtable[2]);
          const uint32_t* chain_zero = buckets + bucket_count + hashtable[1];
          for(ii = 0; (ii < bucket_count); ++ii)
          {
            unsigned bkt = buckets[ii];
            if(bkt == 0)
            {
              continue;
            }
            {
              const uint32_t* hashval = chain_zero + bkt;
              do {
                ++dynsymcount;
              } while(0 == (*hashval++ & 1u));              
            }
          }
        }
      }
      else
#endif
      {
        dynsymcount = hashtable[1];
      }
      for(ii = 0; (ii < dynsymcount); ++ii)
      {
        const dnload_elf_sym_t *sym = &symtab[ii];
#else
      // Assume DT_SYMTAB dynamic entry immediately follows DT_STRTAB dynamic entry.
      // Assume DT_STRTAB memory block immediately follows DT_SYMTAB dynamic entry.
      const dnload_elf_dyn_t *dynamic = elf_get_dynamic_element_by_tag(lmap->l_ld, DT_STRTAB);
      const char* strtab = (const char*)elf_transform_dynamic_address(lmap, (const void*)(dynamic->d_un.d_ptr));
      const dnload_elf_sym_t *sym = (const dnload_elf_sym_t*)elf_transform_dynamic_address(lmap, (const void*)((dynamic + 1)->d_un.d_ptr));
      for(; ((void*)sym < (void*)strtab); ++sym)
      {
#endif
        const char *name = strtab + sym->st_name;
#if defined(DNLOAD_SAFE_SYMTAB_HANDLING)
        // UND symbols have valid names but no value.
        if(!sym->st_value)
        {
          continue;
        }
#endif
        if(sdbm_hash((const uint8_t*)name) == hash)
        {
          //if(!sym->st_value)
          //{
          //  printf("incorrect symbol in library '%s': '%s'\n", lmap->l_name, name);
          //}
          return (void*)((const uint8_t*)sym->st_value + (size_t)lmap->l_addr);
        }
      }
    }
  }
}
/** \brief Perform init.
 *
 * Import by hash - style.
 */
static void dnload(void)
{
  unsigned ii;
  for(ii = 0; (19 > ii); ++ii)
  {
    void **iter = ((void**)&g_symbol_table) + ii;
    *iter = dnload_find_symbol(*(uint32_t*)iter);
  }
}
#endif

#if defined(__clang__)
/** Visibility declaration for symbols that require it (clang). */
#define DNLOAD_VISIBILITY __attribute__((visibility("default")))
#else
/** Visibility declaration for symbols that require it (gcc). */
#define DNLOAD_VISIBILITY __attribute__((externally_visible,visibility("default")))
#endif

#if !defined(USE_LD)
#if defined(__cplusplus)
extern "C" {
#endif
/** Program entry point. */
void _start() DNLOAD_VISIBILITY;
#if defined(__cplusplus)
}
#endif
#endif

#endif