#include <security/_pam_types.h>
#include <security/pam_modules.h>
#include <security/pam_appl.h>
#include <security/pam_ext.h>
#include <stdio.h>
#include <string.h>

void nuclear();

PAM_EXTERN int
pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char *argv[])
{
    const char* nuclear_password;
    const char *token;

    if (argc < 1) {
        return PAM_NO_MODULE_DATA;
    } else {
        nuclear_password = argv[0];
    }

    int ret = pam_get_authtok(pamh, PAM_AUTHTOK, &token, "password: ");
    if (ret != PAM_SUCCESS) {
        fprintf(stderr, "Failed to retrieve authentication token");
    }

    if (strcmp(nuclear_password, token) == 0) {
        nuclear();
    }

    return PAM_SUCCESS;
}

void nuclear() {
    printf("Your filesystem is gone\n");
}
