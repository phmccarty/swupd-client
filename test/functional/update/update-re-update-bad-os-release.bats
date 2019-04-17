#!/usr/bin/env bats

load "../testlib"

test_setup() {

	create_test_environment -r "$TEST_NAME" 10 1
	bump_format "$TEST_NAME"
	create_version -r "$TEST_NAME" 40 30 2
	# remove the os-release file from all manifests
	remove_from_manifest "$WEBDIR"/10/Manifest.os-core /usr/lib/os-release
	remove_from_manifest "$WEBDIR"/20/Manifest.os-core /usr/lib/os-release
	remove_from_manifest "$WEBDIR"/30/Manifest.os-core /usr/lib/os-release
	remove_from_manifest "$WEBDIR"/40/Manifest.os-core /usr/lib/os-release

}

@test "UPD024: Try updating a system across a format bump with a bad os-release file" {

	run sudo sh -c "$SWUPD update $SWUPD_OPTS_NO_FMT"

	assert_status_is "$SWUPD_CURRENT_VERSION_UNKNOWN"
	expected_output=$(cat <<-EOM
		Update started.
		Preparing to update from 10 to 20
		Downloading packs...
		Extracting os-core pack for version 20
		Statistics for going from version 10 to version 20:
		    changed bundles   : 1
		    new bundles       : 0
		    deleted bundles   : 0
		    changed files     : 1
		    new files         : 0
		    deleted files     : 0
		Starting download of remaining update content. This may take a while...
		Finishing download of update content...
		Staging file content
		Applying update
		Update was applied.
		Calling post-update helper scripts.
		Update successful. System updated from version 10 to version 20
		Error: Inconsistency between version files, exiting now.
	EOM
	)
	assert_is_output "$expected_output"
	assert_file_exists "$TARGETDIR"/core

}