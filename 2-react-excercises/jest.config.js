module.exports = {
  setupFiles: ["<rootDir>/src/setupTests.js"],
  transformIgnorePatterns: [
    "node_modules/(?!(bs-platform|reason-react|@glennsl\/bs-jest|bs-enzyme)/)"
  ]
};
