from distutils.core import setup, Extension

tedcoin_hash_module = Extension('tedcoin_hash',
                               sources = ['tedcoinmodule.c',
                                          'tedcoin.c',
										  'sha3/blake.c',
										  'sha3/bmw.c',
										  'sha3/groestl.c',
										  'sha3/jh.c',
										  'sha3/keccak.c',
										  'sha3/skein.c',
										  'sha3/cubehash.c',
										  'sha3/echo.c',
										  'sha3/luffa.c',
										  'sha3/simd.c',
										  'sha3/shavite.c'],
                               include_dirs=['.', './sha3'])

setup (name = 'tedcoin_hashs',
       version = '1.0',
       description = 'Bindings for proof of work used by tedcoin',
       ext_modules = [tedcoin_hash_module])
