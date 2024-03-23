module.exports = {
    branches: ['main'], // Define your default branch name

    plugins: [
        '@semantic-release/commit-analyzer', // Analyzes commit messages to determine the next version.
        '@semantic-release/release-notes-generator', // Generates release notes from commit messages.
        '@semantic-release/changelog', // Updates a CHANGELOG.md file based on the release notes.
        [
            '@semantic-release/exec', // Run a shell command.
            {
                prepareCmd: 'echo ${nextRelease.version} > VERSION' // Write the version to a file.
            }
        ],
        '@semantic-release/github' // Publishes releases on GitHub.
    ]
}
