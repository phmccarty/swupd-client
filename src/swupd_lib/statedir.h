#ifndef __STATEDIR__
#define __STATEDIR__

/**
 * @file
 * @brief Module that handles the statedir
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief Gets the path to the bundle tracking directory in the statedir.
  */
char *statedir_get_tracking_dir(void);

/**
 * @brief Gets the path to the tracking file of the specified bundle in the statedir.
 *
 * @param bundle_name, the name of the bundle
 */
char *statedir_get_tracking_file(const char *bundle_name);

/**
  * @brief Gets the path to the staged directory in the statedir.
  */
char *statedir_get_staged_dir(void);

/**
 * @brief Gets the path to a file in the staged directory in the statedir.
 *
 * @param file_hash, the hash of the file
 */
char *statedir_get_staged_file(char *file_hash);

/**
  * @brief Gets the path to the delta directory in the statedir.
  */
char *statedir_get_delta_dir(void);

/**
  * @brief Gets the path to the download directory in the statedir.
  */
char *statedir_get_download_dir(void);

/**
 * @brief Gets the path to the downloaded fullfile tar in the statedir.
 *
 * @param file_hash, the hash of the file
 */
char *statedir_get_fullfile_tar(char *file_hash);

/**
 * @brief Gets the path to the directory where manifests are stored in the statedir.
 */
char *statedir_get_manifest_root_dir(void);

/**
 * @brief Gets the path to the directory where manifests for a specific version are
 * stored in the statedir.
 *
 * @param version, the version of the manifests directory
 */
char *statedir_get_manifest_dir(int version);

/**
 * @brief Gets the path to the directory where manifests for a specific version are
 * stored in the statedir duplicate (also known as statedir_cache).
 *
 * @param version, the version of the manifests directory
 */
char *statedir_dup_get_manifest_dir(int version);

/**
 * @brief Gets the path to the downloaded manifest tar of the specified
 * component at a certain version in the statedir.
 *
 * @param version, the version of the manifest
 * @param component, either MoM or the name of a bundle
 */
char *statedir_get_manifest_tar(int version, char *component);

/**
 * @brief Gets the path to the manifest of the specified component at a
 * certain version in the statedir.
 *
 * @param version, the version of the manifest
 * @param component, either MoM or the name of a bundle
 */
char *statedir_get_manifest(int version, char *component);

/**
 * @brief Gets the path to the manifest of the specified component at a
 * certain version in the statedir duplicate (also known as statedir_cache).
 *
 * @param version, the version of the manifest
 * @param component, either MoM or the name of a bundle
 */
char *statedir_dup_get_manifest(int version, char *component);

/**
 * @brief Gets the path to the manifest that contains its own hash
 * of the specified component at a certain version in the statedir.
 *
 * @param version, the version of the manifest
 * @param component, either MoM or the name of a bundle
 * @param manifest_hash, the hash of the manifest
 */
char *statedir_get_hashed_manifest(int version, char *component, char *manifest_hash);

/**
  * @brief Gets the path to the manifest delta directory in the statedir.
  */
char *statedir_get_manifest_delta_dir(void);

/**
 * @brief Gets the path to the manifest delta of the specified bundle
 * going from one version to another version in the statedir.
 *
 * @param bundle, the name of a bundle
 * @param from_version, the from version for the delta
 * @param to_version, the to version for the delta
 */
char *statedir_get_manifest_delta(char *bundle, int from_version, int to_version);

/**
 * @brief Gets the path to the temporary name given to a downloaded
 * fullfile tar while being untarred in the statedir.
 *
 * @param file_hash, the hash of the file
 */
char *statedir_get_fullfile_renamed_tar(char *file_hash);

/**
 * @brief Gets the path to the telemetry record in the statedir.
 *
 * @param record, the name of the telemetry record
 */
char *statedir_get_telemetry_record(char *record);

/**
 * @brief Gets the path to the swupd lock file in the statedir.
 */
char *statedir_get_swupd_lock(void);

/**
 * @brief Gets the path to the directory where delta-packs are stored in the statedir.
 */
char *statedir_get_delta_pack_dir(void);

/**
 * @brief Gets the path to the delta pack tar of the specified bundle
 * going from one version to another version in the statedir.
 *
 * @param bundle, the name of a bundle
 * @param from_version, the from version for the delta
 * @param to_version, the to version for the delta
 */
char *statedir_get_delta_pack(char *bundle, int from_version, int to_version);
/**
 * @brief Gets the path to the version file in the statedir.
 */
char *statedir_get_version(void);

/**
 * @brief Creates the required directories in the statedir.
 *
 * @param path The path of the statedir
 */
int statedir_create_dirs(const char *path);

/**
 * @brief Sets the path to the statedir.
 *
 * @param path The path of the statedir
 */
bool statedir_set_path(char *path);

/**
 * @brief Sets the path to the duplicate (cache) of the statedir.
 *
 * @param path The path of the statedir duplicate
 */
bool statedir_dup_set_path(char *path);

#ifdef __cplusplus
}
#endif

#endif
