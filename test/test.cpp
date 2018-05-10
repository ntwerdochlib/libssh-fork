// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#define LIBSSH_STATIC
#include "config.h"
#include "libssh/libssh.h"
#include "libssh/pki.h"
#include "libssh/keys.h"


static constexpr int NumKeys = 3;
const char* pkey[NumKeys] = {
	// ECDSA 384
	"-----BEGIN OPENSSH PRIVATE KEY-----\nb3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAAAiAAAABNlY2RzYS1zaGEyLW5pc3RwMzg0AAAACG5pc3RwMzg0AAAAYQRm3QyeIOI1eLM6jBy9nP62pd5cx7AdoGqbSgLBvT+L/YtlCT1VoCsUbzg2xJ5R3pgJdMxE16Ippvu9MrVQY4Ro2qgZTxCJSNrjziHHC9w8w0GYo3qT0PS0gMztO8+IH7MAAADg/toMuv7aDLoAAAATZWNkc2Etc2hhMi1uaXN0cDM4NAAAAAhuaXN0cDM4NAAAAGEEZt0MniDiNXizOowcvZz+tqXeXMewHaBqm0oCwb0/i/2LZQk9VaArFG84NsSeUd6YCXTMRNeiKab7vTK1UGOEaNqoGU8QiUja484hxwvcPMNBmKN6k9D0tIDM7TvPiB+zAAAAMDtzC9qx7PtDH6qcGffSt0FiyvFIuOx/SlXRtwQuuabf91uDDMEqT6WdP0c3S2+t+AAAABJlY2RzYS1rZXktMjAxODA1MDgBAgMEBQY=\n-----END OPENSSH PRIVATE KEY-----\n",
	// RSA
	"-----BEGIN OPENSSH PRIVATE KEY-----\nb3BlbnNzaC1rZXktdjEAAAAABG5vbmUAAAAEbm9uZQAAAAAAAAABAAABFQAAAAdzc2gtcnNhAAAAASUAAAEBALNoOQS4RAQV+28mj+D+6eiL7cw+5Ko0KQT4XvD4roADN5Re7aYHPAIs/Exjs9uf7kycwCUxxLyOCyBMsVq/zNn1cwXP3qJRNFN6zbtW70MzBxZ5m0CACjOmMWJIHDvfDUE2zJTdGRNR8qMoos4RSlIYo6p8t5kSbH5us3SuVwidfJbCZQkvrbDKFOhPU6C+NZJ5bLxARYe9LGEEyQAHaZ39TSY/41oVUD+tnP8DPoKrMz1nhSNRQhfXxwImZtBrf5ywEzO4Z14vVdHOxvS0ncmfINtRDhVLxbihQywnMtBYF2Kj7BPUIalKn7H4Wjw1pvjLOgDhelEAm6D2GBisLxsAAAPgNzY9UTc2PVEAAAAHc3NoLXJzYQAAAQEAs2g5BLhEBBX7byaP4P7p6IvtzD7kqjQpBPhe8PiugAM3lF7tpgc8Aiz8TGOz25/uTJzAJTHEvI4LIEyxWr/M2fVzBc/eolE0U3rNu1bvQzMHFnmbQIAKM6YxYkgcO98NQTbMlN0ZE1HyoyiizhFKUhijqny3mRJsfm6zdK5XCJ18lsJlCS+tsMoU6E9ToL41knlsvEBFh70sYQTJAAdpnf1NJj/jWhVQP62c/wM+gqszPWeFI1FCF9fHAiZm0Gt/nLATM7hnXi9V0c7G9LSdyZ8g21EOFUvFuKFDLCcy0FgXYqPsE9QhqUqfsfhaPDWm+Ms6AOF6UQCboPYYGKwvGwAAAAElAAABAA6L6PKLeyLtBox4v47Ij4GOzhd6uJgtviL/YaTV5KKYeiDJbTb5qutrbmcPAL7Hxzak7PwYysMuHJPqiuuur76lMtb1LboiQoNPJXAN97lXKhaUPQU60GUNeaAvXDw0rgw04Ce+5luDL1lWUmO8NnVb8ZgzoC8Bfmsdu4YATD734GS76yTwBERt4y5y8dtB8IJUpoNc+3PDwLfGbrIBxxtgPBcI/Vl8tmx2IJAiHF6efAr5jkmdqgWvxzkgyng0MK+DgZEdv9n0+DOzIN6VMdYhVrOAFeb4nfFZoYG9AYNPEKmPjc2fV+fi7skdov/npx/766Pv/V5XKeWIY3zgvSUAAACAI/hZOa65Jyx7FB6DASJUG/sKQm09xj81ODQeFC6DTCuB9rASoG3I2m3jY9H2zoA2SZ3/ZZUOWmkIMyddnKJucFsZq4IAF2y4ZHuK73uWBcy0OzpFQHN6vTv+D6ZonolOLSiknfVaPYDkZloELO9u/Sohzs+rgYTh4XnQ6Rr6NnQAAACBAOBgZPaVFowQKbeDgXWvJjQP/16YaZRg1DvMr755SVgLDJcIv0jMVL+zcOVIXCNkTbzaK/39953SOF7v1hIzEnop9YflfjC3Vr+LEfjMUHJgBfvVTYbd0tnpP7qdT1SElJ8AZZYqWZCtDmgIuPJ77TrOpn4xFBQoHT+RE/uhfy/NAAAAgQDMsU/FAd5CVKprfUQ3DBVrOxCzJQaT6HqnucW1SKgklqMmVrxl6L5xUovQxQJn5LrR2+BW7sEd/3zO/GaTfYACU2SipctN0WChHnDjbzQaGKiiYC0jwX6lLrrApBIg+Emq4akrrCKqJaK2o3yNbB9e9QG26egxSAWsq6VRcwPihwAAACFyc2Eta2V5LVJNVFBMV1QwNDY3Ni1udHdlcmRvY2hsaWIBAgMEBQYHCAkKCww=\n-----END OPENSSH PRIVATE KEY-----\n",
	// DSA
	"-----BEGIN OPENSSH PRIVATE KEY-----\n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\n-----END OPENSSH PRIVATE KEY-----\n",
};

void test()
{
	ssh_key key[NumKeys];

	for (int i = 0; i < NumKeys; ++i) {
		key[i];
		int rc = ssh_pki_import_privkey_base64(pkey[i], 0, 0, 0, &key[i]);
		if (rc != SSH_OK) {
			if (key[i]) {
				printf("Failed to import openssh private key\n");
			} else {
				printf("Failed to import openssh private key %s\n", ssh_key_type_to_char(key[i]->type));
			}
			key[i] = 0;
			continue;
		}
		printf("Key imported %s\n", ssh_key_type_to_char(key[i]->type));
	}

	for (int i = 0; i < NumKeys; ++i) {
		ssh_key_free(key[i]);
	}
}

int main()
{
	#if 0
	ERR_load_CRYPTO_strings();
	test();
	return 0;
	#endif

	ssh_init();
	ssh_session ssh = ssh_new();

	ssh_key key; // = ssh_key_new();
	int rc = ssh_pki_import_privkey_base64(pkey[0], 0, 0, 0, &key);
	if (rc != SSH_OK) {
		if (key) {
			printf("Failed to import openssh private key\n");
		} else {
			printf("Failed to import openssh private key %s\n", ssh_key_type_to_char(key->type));
		}
		goto done;
	}
	printf("Key imported %s\n", ssh_key_type_to_char(key->type));
	
	long timeout = 60;
	ssh_options_set(ssh, SSH_OPTIONS_TIMEOUT, &timeout);
	ssh_options_set(ssh, SSH_OPTIONS_HOST, "ruth.networkstreaming.local");
	//ssh_options_set(ssh, SSH_OPTIONS_HOST, "10.200.9.104");
	ssh_options_set(ssh, SSH_OPTIONS_USER, "ntwerdochlib");

	rc = ssh_connect(ssh);
	if (rc != SSH_OK) {
		printf("failed to connect\n");
		goto done;
	}

	rc = ssh_userauth_publickey(ssh, NULL, key);
	if (rc != SSH_AUTH_SUCCESS) {
		printf("authorization failed\n");
		goto done;
	}

	int openssh_version = ssh_get_openssh_version(ssh);
	if (openssh_version > 0) {
		printf("Server is OpenSSH version %X\n", openssh_version);
	}

	ssh_disconnect(ssh);

	done:
	ssh_key_free(key);
	ssh_free(ssh);

	return 0;
}

